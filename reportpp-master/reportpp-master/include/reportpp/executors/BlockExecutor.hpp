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

#ifndef BLOCK_EXECUTOR_HPP
#define BLOCK_EXECUTOR_HPP

#include <algorithm>
#include <list>
#include <memory>
#include "reportpp/templates/operation/Operation.hpp"
#include "reportpp/support/Callers.hpp"

namespace reportpp {
namespace executors {

class BlockExecutor {
public:
  BlockExecutor() { }
  ~BlockExecutor() { }

  template< typename T >
  void appendOperation(const T &op) {
    operations_.emplace_back(T(op));
  }

  void init(ReportGlobals &glob) {
    std::for_each(operations_.begin(), operations_.end(), InitCaller(glob));
  }

  void end(ReportGlobals &glob) {
    std::for_each(operations_.begin(), operations_.end(), EndCaller(glob));
  }

  void finalize(ReportGlobals &glob) {
    std::for_each(operations_.begin(), operations_.end(), FinalizeCaller(glob));
  }

private:
  std::list< Operation > operations_;
};

}} // namespace reportpp::executors

#endif /* ifndef BLOCK_EXECUTOR_HPP */
