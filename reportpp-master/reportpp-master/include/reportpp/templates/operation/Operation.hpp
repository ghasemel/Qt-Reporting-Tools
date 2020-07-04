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

#ifndef PDF_OPERATION_H
#define PDF_OPERATION_H

#include "reportpp/ReportGlobals.hpp"

/** Represents single operation over the pdf document.
 * Three methods needs to be implemented:
 * - \c init which is called at the begin of page creation
 * - \c end  which is called at the end of page creation, before passing to the
 * next page
 * - \c finalize which is called at document finalization, when all pages are
 * created and filled with input data. This stage may be useful, as an example,
 * for printing the number of pages available in the document or for creating
 * an index.
 */
class Operation {
public:
  virtual void init    (ReportGlobals &glob) { }
  virtual void end     (ReportGlobals &glob) { }
  virtual void finalize(ReportGlobals &glob) { }
};

#endif /* ifndef PDF_OPERATION_H */
