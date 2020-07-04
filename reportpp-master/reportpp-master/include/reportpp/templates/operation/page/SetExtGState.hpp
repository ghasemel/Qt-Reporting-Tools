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

#ifndef PDF_PAGE_SETEXTGSTATE_OPERATION_H
#define PDF_PAGE_SETEXTGSTATE_OPERATION_H

#include "../Operation.hpp"

class SetExtGState: public Operation {
public:
  SetExtGState(HPDF_ExtGState ext_gstate):
    Operation(),
    ext_gstate_(ext_gstate),

  { }

  void init(ReportGlobals &glob) {
    HPDF_Page_SetExtGState(glob.pages.back(), ext_gstate_);
  }

  void end     (ReportGlobals &glob) { }
  void finalize(ReportGlobals &glob) { }

private:
  HPDF_ExtGState ext_gstate_;

};

#endif /* ifndef PDF_PAGE_SETEXTGSTATE_OPERATION_H */