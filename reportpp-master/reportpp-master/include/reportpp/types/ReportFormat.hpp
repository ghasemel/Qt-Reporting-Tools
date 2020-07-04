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

#ifndef REPORTPP_TYPES_REPORT_FORMAT_H
#define REPORTPP_TYPES_REPORT_FORMAT_H

#include "reportpp/types/PageFormat.hpp"

#include <ostream>
#include <vector>

namespace reportpp {
namespace types {

class ReportFormat {
public:
    ReportFormat(): initialized(5, false) {}
    ReportFormat(PageFormat format, float marginTop, float marginBottom, float marginLeft, float marginRight):
        pageFormat_(format),
        margins(marginTop, marginBottom, marginLeft, marginRight),
        initialized(5, true)
    {}
    ReportFormat(const ReportFormat &other, const ReportFormat &defaults): ReportFormat(other) { pullNotInitialized(defaults); }
    ~ReportFormat() { }
    
    void setFormat(const PageFormat &pageFormat) { pageFormat_ = pageFormat; }
    void setMarginTop(float marginTop) { margins.top = marginTop; }
    void setMarginBottom(float marginBottom) { margins.bottom = marginBottom; }
    void setMarginLeft(float marginLeft) { margins.left = marginLeft; }
    void setMarginRight(float marginRight) { margins.right = marginRight; }
    
    PageFormat getFormat() const { return pageFormat_; }
    float getMarginTop() const { return margins.top; }
    float getMarginBottom() const { return margins.bottom; }
    float getMarginLeft() const { return margins.left; }
    float getMarginRight() const { return margins.right; }
    
    void pullNotInitialized(const ReportFormat &parent) {
        if (!initialized[0]) {
            setFormat(parent.getFormat());
            initialized[0] = true;
        }
        if (!initialized[1]) {
            setMarginTop(parent.getMarginTop());
            initialized[1] = true;
        }
        if (!initialized[2]) {
            setMarginBottom(parent.getMarginBottom());
            initialized[2] = true;
        }
        if (!initialized[3]) {
            setMarginLeft(parent.getMarginLeft());
            initialized[3] = true;
        }
        if (!initialized[4]) {
            setMarginRight(parent.getMarginRight());
            initialized[4] = true;
        }
    }

private:
    PageFormat pageFormat_;
    struct Rect {
        float top;
        float bottom;
        float left;
        float right;
        
        Rect() {}
        Rect(float _top, float _bottom, float _left, float _right):
            top(_top),
            bottom(_bottom),
            left(_left),
            right(_right)
        {}
    } margins;
    std::vector<bool> initialized;
};

}} // namespace reportpp::types

std::ostream& operator<<(std::ostream &os, const reportpp::types::ReportFormat &obj);

#endif /* ifndef REPORTPP_TYPES_REPORT_FORMAT_H */
