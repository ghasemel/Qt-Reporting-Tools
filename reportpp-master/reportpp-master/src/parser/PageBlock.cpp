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

#include "reportpp/parser/PageBlock.hpp"

#include <iostream>

namespace reportpp {
namespace parser {

void PageBlock::text() {
    std::clog << "PageBlock::text() called" << std::endl;
}

void PageBlock::label() {
    std::clog << "PageBlock::label() called" << std::endl;
}

void PageBlock::shape() {
    std::clog << "PageBlock::shape() called" << std::endl;
}

void PageBlock::image() {
    std::clog << "PageBlock::image() called" << std::endl;
}

void PageBlock::post_pageBlock() {
    std::clog << "PageBlock::post_pageBlock() called" << std::endl;
}

}} // namespace reportpp::parser
