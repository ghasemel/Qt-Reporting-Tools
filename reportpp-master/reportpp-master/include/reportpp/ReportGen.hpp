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

#ifndef REPORT_GEN_HPP
#define REPORT_GEN_HPP

#include <list>
#include <memory>

#include "reportpp/ReportGlobals.hpp"
#include "reportpp/executors/PageExecutor.hpp"
#include "reportpp/executors/DataPageExecutor.hpp"

namespace reportpp {

class ReportGen {
public:
  ReportGen();
  ReportGen(const ReportGen&);
  ~ReportGen();

  void setFrontPage(const reportpp::executors::PageExecutor &page, reportpp::types::ReportFormat defaultFormat);
  void setFirstPage(const reportpp::executors::PageExecutor &page, reportpp::types::ReportFormat defaultFormat);
  void setDataPage(const reportpp::executors::PageExecutor &page, reportpp::types::ReportFormat defaultFormat);
  void setLastPage(const reportpp::executors::PageExecutor &page, reportpp::types::ReportFormat defaultFormat);

  void setReportHeaders(const std::list< std::string > &headers) { globals.headers = headers; }

  void addRecord(const std::list< std::string > &record);

  void finalizeDocument();
  
  void saveToFile(const std::string &fileName) const;

private:
  std::unique_ptr< reportpp::executors::PageExecutor >                  frontPage_; ///< Front page executor
  std::list< std::unique_ptr< reportpp::executors::DataPageExecutor > > dataPages_; ///< list of data page executors
  std::unique_ptr< reportpp::executors::PageExecutor >                  lastPage_;  ///< Last page executor

  ReportGlobals globals;
  std::list< std::unique_ptr< reportpp::executors::DataPageExecutor > >::const_iterator curDataPage_;
  bool hasFirstPage_; ///< \c true if the first item of \c dataPages_ is a custom first page
  bool isFinalized;  ///< \c true when the document has been finalized (no more changes are possible)

  void initPdfDocument();
  void moveItrToNextPage();
};

} // namespace reportpp

#endif /* ifndef REPORT_GEN_HPP */
