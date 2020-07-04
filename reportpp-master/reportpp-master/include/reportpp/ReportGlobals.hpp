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

#ifndef REPORT_GLOBALS_HPP
#define REPORT_GLOBALS_HPP

#include <hpdf.h>
#include <list>
#include <string>

struct ReportGlobals {
  HPDF_Doc pdf; ///< PDF document handler
  std::list< HPDF_Page > pages; ///< List of all previously generated pages in current document
  unsigned int gmode; // actual graphics mode (see HPDF_GMODE_* in hpdf_constants.h)
  std::list< std::string > headers;

  ReportGlobals(): pdf(nullptr), gmode(0) { }
};

#endif /* ifndef REPORT_GLOBALS_HPP */
