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

#ifndef PAGE_EXECUTOR_HPP
#define PAGE_EXECUTOR_HPP

#include "reportpp/executors/BlockExecutor.hpp"
#include "reportpp/types/ReportFormat.hpp"

namespace reportpp {
namespace executors {

class PageExecutor {
public:
  PageExecutor() { }
  ~PageExecutor() { }

  void setDefaultFormat(const reportpp::types::ReportFormat &defValues) {
    reportFormat.pullNotInitialized(defValues);
  }

  void setFormat(const reportpp::types::PageFormat &pageFormat) { reportFormat.setFormat(pageFormat); }
  void setMarginTop   (const float margin) { reportFormat.setMarginTop   (margin); }
  void setMarginBottom(const float margin) { reportFormat.setMarginBottom(margin); }
  void setMarginLeft  (const float margin) { reportFormat.setMarginLeft  (margin); }
  void setMarginRight (const float margin) { reportFormat.setMarginRight (margin); }

  BlockExecutor &addBlock() {
    blocks_.emplace_back(BlockExecutor());
    return blocks_.back();
  }

  void init(ReportGlobals &glob) {
    glob.pages.emplace_back(HPDF_AddPage(glob.pdf));
    std::for_each(blocks_.begin(), blocks_.end(), InitCaller(glob));
  }

  void end(ReportGlobals &glob) {
    std::for_each(blocks_.begin(), blocks_.end(), EndCaller(glob));
  }

  void finalize(ReportGlobals &glob, unsigned int pageNo) {
    std::for_each(blocks_.begin(), blocks_.end(), FinalizeCaller(glob));
  }

private:
  reportpp::types::ReportFormat reportFormat;
  std::list< BlockExecutor > blocks_;
};

}} // namespace reportpp::executors

#endif /* ifndef PAGE_EXECUTOR_HPP */
