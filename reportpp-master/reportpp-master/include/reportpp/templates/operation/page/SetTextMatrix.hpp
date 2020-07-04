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

#ifndef PDF_PAGE_SETTEXTMATRIX_OPERATION_H
#define PDF_PAGE_SETTEXTMATRIX_OPERATION_H

#include "../Operation.hpp"

class SetTextMatrix: public Operation {
public:
  SetTextMatrix(HPDF_REAL a, HPDF_REAL b, HPDF_REAL c, HPDF_REAL d, HPDF_REAL x, HPDF_REAL y):
    Operation(),
    a_(a),
    b_(b),
    c_(c),
    d_(d),
    x_(x),
    y_(y),

  { }

  void init(ReportGlobals &glob) {
    HPDF_Page_SetTextMatrix(glob.pages.back(), a_, b_, c_, d_, x_, y_);
  }

  void end     (ReportGlobals &glob) { }
  void finalize(ReportGlobals &glob) { }

private:
  HPDF_REAL a_;
  HPDF_REAL b_;
  HPDF_REAL c_;
  HPDF_REAL d_;
  HPDF_REAL x_;
  HPDF_REAL y_;

};

#endif /* ifndef PDF_PAGE_SETTEXTMATRIX_OPERATION_H */