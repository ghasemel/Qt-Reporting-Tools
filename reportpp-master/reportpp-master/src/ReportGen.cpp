/*
 * This file is part of reportpp.
 *
 * reportpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * reportpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with reportpp.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * ---
 * Copyright (C) 2014, mickey <mickey.mouse-1985@libero.it>
 */

#include <cassert>
#include <sstream>

#include "reportpp/ReportGen.hpp"

using reportpp::executors::PageExecutor;

namespace reportpp {

// error handling method
void hpdf_error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data) {
  std::stringstream strs;
  strs << "PDF library error: code: 0x" << std::hex << error_no;
  strs << ", detail: " << std::dec << detail_no;
  throw std::runtime_error(strs.str());
}

ReportGen::ReportGen():
  hasFirstPage_(false),
  isFinalized(false)
{ }

ReportGen::ReportGen(const ReportGen &other) {
  // TODO
}

ReportGen::~ReportGen() {
  if (nullptr != globals.pdf) HPDF_Free(globals.pdf);
}


void ReportGen::setFrontPage(const reportpp::executors::PageExecutor &page, reportpp::types::ReportFormat defaultFormat) {
  // TODO
}

void ReportGen::setFirstPage(const reportpp::executors::PageExecutor &page, reportpp::types::ReportFormat defaultFormat) {
  // TODO
}

void ReportGen::setDataPage(const reportpp::executors::PageExecutor &page, reportpp::types::ReportFormat defaultFormat) {
  // TODO
}

void ReportGen::setLastPage(const reportpp::executors::PageExecutor &page, reportpp::types::ReportFormat defaultFormat) {
  // TODO
}

// PageExecutor &ReportGen::getFrontPage() {
//   if (nullptr == frontPage_) {
//     frontPage_ = std::unique_ptr< PageExecutor >(new PageExecutor());
//   }
//   return *frontPage_;
// }
// 
// DataPageExecutor &ReportGen::getFirstPage() {
//   if (!hasFirstPage_) {
//     dataPages_.emplace_back(new DataPageExecutor());
//   }
//   return *(dataPages_.front());
// }
// 
// DataPageExecutor &ReportGen::addDataPage() {
//   dataPages_.emplace_back(new DataPageExecutor());
//   return *(dataPages_.back());
// }
// 
// PageExecutor &ReportGen::getLastPage() {
//   if (nullptr == lastPage_) {
//     lastPage_ = std::unique_ptr< PageExecutor >(new PageExecutor());
//   }
//   return *(lastPage_);
// }

void ReportGen::addRecord(const std::list< std::string > &record) {
  if (nullptr == globals.pdf) initPdfDocument();
  bool ok = (*curDataPage_)->addRecord(globals, record);
  if (!ok) {
    // not enough room in current page for the record
    (*curDataPage_)->end(globals);
    moveItrToNextPage();
    ok = (*curDataPage_)->addRecord(globals, record);
    assert(ok); // otherwise means that even on a empty data page there is not enought room for this record
    (*curDataPage_)->init(globals);
  }
}

void ReportGen::finalizeDocument() {
  if (nullptr != lastPage_) {
    lastPage_->init(globals);
    lastPage_->end(globals);
  }
  if (nullptr != frontPage_) frontPage_->finalize(globals, -1);
  curDataPage_ = dataPages_.begin();
  for (unsigned int index = 0; index < globals.pages.size(); ++index) {
    (*curDataPage_)->finalize(globals, index);
    moveItrToNextPage();
  }
  if (nullptr != lastPage_) lastPage_->finalize(globals, -1);
  isFinalized = true;
}

void ReportGen::saveToFile(const std::string &fileName) const {
  HPDF_SaveToFile(globals.pdf, fileName.data());
}

void ReportGen::initPdfDocument() {
  assert(nullptr == globals.pdf);
  globals.pdf = HPDF_New(hpdf_error_handler, nullptr);
  if (nullptr != frontPage_) {
    frontPage_->init(globals);
    frontPage_->end(globals);
  }
  curDataPage_ = dataPages_.begin();
  (*curDataPage_)->init(globals);
}

void ReportGen::moveItrToNextPage() {
  curDataPage_++;
  if (dataPages_.end() == curDataPage_) {
    curDataPage_ = dataPages_.begin();
    if (hasFirstPage_) curDataPage_++; // skip custom first page when looping
  }
}

} // namespace reportpp
