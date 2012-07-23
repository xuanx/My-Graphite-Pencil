/* =====================================================================================
 *
 *       Filename:  line.cpp
 *
 *    Description:  definite methods for line
 *
 *        Version:  1.0
 *        Created:  2012年06月02日 20时49分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  ssspace
 *
 * ===================================================================================== */
#include "../math/math.h"
#include "line.h"

bool line::set(const V2D& v1, const V2D& v2) {
    float x1 = const_cast<V2D&>(v1)[V2D::X], y1 = const_cast<V2D&>(v1)[V2D::Y];
    float x2 = const_cast<V2D&>(v2)[V2D::X], y2 = const_cast<V2D&>(v2)[V2D::Y];
    if (fabs(x1 - x2) < DIFF) {
        if (fabs(y1 - y2) < DIFF)
            return false;
        _a = 1;
        _b = 0;
        _c = x1;
    }
    else {
        float k  = (y1 - y2) / (x1 - x2);
        _a = k;
        _b = -1;
        _c = y1 - k * x1;
    }
    return true;  
}

line::line(float a, float b, float c): _a(a), _b(b), _c(c) {}
line::line(const line& l): _a(l._a), _b(l._b), _c(l._c) {}
line::line(const V2D& v1, const V2D& v2){ set(v1, v2); }

line& line::operator = (const line& l) {
    _a = l._a;
    _b = l._b;
    _c = l._c;
    return *this;
}

bool line::isParallel(const line& l) {
    return fabs(_a * l._b - l._a * _b) < DIFF;
}
V2D line::operator ^ (const line& l) {

    float delt = _a * l._b - l._a * _b;
    if (fabs(delt) < DIFF)
        return V2D();
    return V2D((l._c * _b - _c * l._b) / delt, (_c * l._a - l._c * _a) / delt);
}
