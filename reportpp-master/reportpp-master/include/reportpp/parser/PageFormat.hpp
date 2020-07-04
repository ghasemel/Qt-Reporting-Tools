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

#ifndef REPORTPP_TYPES_PAGEFORMAT_H
#define REPORTPP_TYPES_PAGEFORMAT_H

#include "reportpp/parser/reportpp-pskel.hxx"

namespace reportpp {
namespace parser {

class PageFormat: public tPageFormat_pskel, public ::xml_schema::string_pimpl {
public:
    void pre() {}
    reportpp::types::PageFormat post_tPageFormat();
};

}} // namespace reportpp::parser

std::ostream& operator << (std::ostream& os, const reportpp::types::PageFormat& obj);

#endif // REPORTPP_TYPES_PAGEFORMAT_H
