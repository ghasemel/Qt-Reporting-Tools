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

#ifndef SUPPORT_CALLERS_HPP
#define SUPPORT_CALLERS_HPP

#include "../ReportGlobals.hpp"

class InitCaller {
public:
  InitCaller(ReportGlobals &glob): glob_(glob) { }

  template< typename T >
  void operator()(T &item) { item.init(glob_); }
private:
  ReportGlobals &glob_;
};

class EndCaller {
public:
  EndCaller(ReportGlobals &glob): glob_(glob) { }

  template< typename T >
  void operator()(T &item) { item.end(glob_); }
private:
  ReportGlobals &glob_;
};

class FinalizeCaller {
public:
  FinalizeCaller(ReportGlobals &glob): glob_(glob) { }

  template< typename T >
  void operator()(T &item) { item.finalize(glob_); }
private:
  ReportGlobals &glob_;
};

#endif /* ifndef SUPPORT_CALLERS_HPP */
