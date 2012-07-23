/* =====================================================================================
 *
 *       Filename:  triangle.cpp
 *
 *    Description:  definite methods for triangle
 *
 *        Version:  1.0
 *        Created:  2012年06月02日 22时26分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  ssspace
 *
 * ===================================================================================== */

#include "triangle.h"
#include "../math/math.h"

void triangle::set(const V2D& v1, const V2D& v2, const V2D& v3) {
        vertex[A] = v1;
        vertex[B] = v2;
        vertex[C] = v3;
}

triangle::triangle() {
    set(V2D(), V2D(), V2D());
}
triangle::triangle(const V2D& v1, const V2D& v2, const V2D& v3) {
    set(v1, v2, v3);
}
triangle::triangle(const triangle& t) {
    set(t.vertex[A], t.vertex[B], t.vertex[C]);
}

triangle& triangle::operator = (const triangle& t) {
    set(t.vertex[A], t.vertex[B], t.vertex[C]);
    return *this;
}

V2D& triangle::operator [] (VERTEX v) {
    return vertex[v];
}

bool triangle::isInner(const V2D& v) {
    float e_1 = (vertex[B] - vertex[A]) ^ (v - vertex[A]);
    float e_2 = (vertex[C] - vertex[B]) ^ (v - vertex[B]);
    float e_3 = (vertex[A] - vertex[C]) ^ (v - vertex[C]);

    if ((e_1 >= 0 && e_2 >= 0 && e_3 >= 0) || (e_1 <= 0 && e_2 <= 0 && e_3 <= 0)) 
        return true;
    return false;
}

std::set<V2D> triangle::rasterization() {
    float left  = MIN3(vertex[A][V2D::X], vertex[B][V2D::X], vertex[C][V2D::X]);
    float right = MAX3(vertex[A][V2D::X], vertex[B][V2D::X], vertex[C][V2D::X]);
    float up    = MAX3(vertex[A][V2D::Y], vertex[B][V2D::Y], vertex[C][V2D::Y]);
    float down  = MIN3(vertex[A][V2D::Y], vertex[B][V2D::Y], vertex[C][V2D::Y]);
    std::set<V2D> points;

    for (float x = left; x <= right; ++x)
        for (float y = down; y <= up; ++y) {
            V2D v(x, y);
            if (isInner(v))
                points.insert(v);
        }
    return points;
}

triangle& triangle::scale(float s) {
    vertex[A].scale(s);
    vertex[B].scale(s);
    vertex[C].scale(s);
    return *this;
}
