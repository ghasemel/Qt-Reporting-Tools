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

#ifndef TYPES_REPORTPP_H
#define TYPES_REPORTPP_H

#include <ostream>

namespace reportpp {
namespace types {

enum class PageFormat {
  letter,
  legal,
  a3,
  a4,
  a5,
  b4,
  b5,
  executive,
  us4x6,
  us4x8,
  us5x7,
  comm10
};

}} // namespace reportpp::types

std::ostream& operator<<(std::ostream &os, const reportpp::types::PageFormat &obj);

#endif /* ifndef TYPES_REPORTPP_H */
