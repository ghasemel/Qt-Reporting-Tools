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

#ifndef REPORTPP_REPORT_PAGE_H
#define REPORTPP_REPORT_PAGE_H

#include "reportpp/parser/reportpp-pskel.hxx"

namespace reportpp {
namespace parser {

class ReportPage: public ReportPage_pskel {
public:
    void pre() { }

    void block() { }

    void pageFormat(const ::reportpp::types::PageFormat &pageFormat) { result_.setFormat(pageFormat); }
    void marginTop   (float margin) { result_.setMarginTop   (margin); }
    void marginBottom(float margin) { result_.setMarginBottom(margin); }
    void marginLeft  (float margin) { result_.setMarginLeft  (margin); }
    void marginRight (float margin) { result_.setMarginRight (margin); }

    ::reportpp::executors::PageExecutor post_ReportPage() { return result_; }

private:
    ::reportpp::executors::PageExecutor result_;
};

}} // namespace reportpp::parser

#endif // REPORTPP_REPORT_PAGE_H
