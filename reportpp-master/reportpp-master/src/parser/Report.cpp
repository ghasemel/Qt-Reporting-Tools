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

#include "reportpp/parser/PageFormat.hpp"
#include "reportpp/parser/Report.hpp"
#include "reportpp/executors/PageExecutor.hpp"

#include <iostream>

namespace reportpp {
namespace parser {

void Report::pre() {
    std::clog << "Report::pre() called" << std::endl;
    defaultReportFormat = ::reportpp::types::ReportFormat(::reportpp::types::PageFormat::a4, 0.0, 0.0, 0.0, 0.0);
}

void Report::frontPage(const ::reportpp::executors::PageExecutor &frontPage) {
    reportGen_.setFrontPage(frontPage, defaultReportFormat);
}

void Report::firstPage(const ::reportpp::executors::PageExecutor &firstPage) {
    reportGen_.setFirstPage(firstPage, defaultReportFormat);
}

void Report::dataPage(const ::reportpp::executors::PageExecutor &dataPage) {
    reportGen_.setDataPage(dataPage, defaultReportFormat);
}

void Report::lastPage(const ::reportpp::executors::PageExecutor &lastPage) {
    reportGen_.setLastPage(lastPage, defaultReportFormat);
}

void Report::pageFormat(const ::reportpp::types::PageFormat &format) {
    std::clog << "Report::pageFormat() called with " << format << " arg" << std::endl;
    defaultReportFormat.setFormat(format);
}

void Report::marginTop(float value) {
    std::clog << "Report::marginTop() called with " << value << " arg" << std::endl;
    defaultReportFormat.setMarginTop(value);
}

void Report::marginBottom(float value) {
    std::clog << "Report::marginBottom() called with " << value << " arg" << std::endl;
    defaultReportFormat.setMarginBottom(value);
}

void Report::marginLeft(float value) {
    std::clog << "Report::marginLeft() called with " << value << " arg" << std::endl;
    defaultReportFormat.setMarginLeft(value);
}

void Report::marginRight(float value) {
    std::clog << "Report::marginRight() called with " << value << " arg" << std::endl;
    defaultReportFormat.setMarginRight(value);
}

}} // namespace reportpp::parser
