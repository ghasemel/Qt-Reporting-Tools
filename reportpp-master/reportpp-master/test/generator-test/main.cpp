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

#include <reportpp/ReportGen.hpp>
#include <reportpp/operation/page/Rectangle.hpp>
#include <reportpp/operation/Stroke.hpp>
#include <reportpp/operation/page/SetSize.hpp>

void initFrontPage(PageExecutor &fp) {
  BlockExecutor &bEx = fp.addBlock();
  bEx.appendOperation(PageSetSize(PageSize::a5, PageDirection::landscape));
  bEx.appendOperation(SetRGBFill(0.88, 0.88, 0.95));
  bEx.appendOperation(RectangleOp(15, 10, 30, 45));
  bEx.appendOperation(StrokeOp());
}

int main() {
  ReportGen gen;
  initFrontPage(gen.getFrontPage());
  DataPageExecutor &dataPage = gen.addDataPage();
  BlockExecutor &dpBlockEx = dataPage.addBlock();
  RectangleOp rect(10, 20, 30, 40);
  dpBlockEx.appendOperation(rect);
  dpBlockEx.appendOperation(StrokeOp());
  std::list< std::string > record = { "Hello, World!" };
  gen.addRecord(record);
  gen.finalizeDocument();
  gen.saveToFile("report.pdf");
}
