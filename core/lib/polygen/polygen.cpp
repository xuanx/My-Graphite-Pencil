/* =====================================================================================
 *
 *       Filename:  polygen.cpp
 *
 *    Description:  definite methods for polygen
 *
 *        Version:  1.0
 *        Created:  2012年06月02日 23时36分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  ssspace
 *
 * ===================================================================================== */
#include "polygen.h"

polygen::polygen() {}
polygen::polygen(const V2D* fst, const V2D* lst) {
    vertices = std::vector<V2D>(fst, lst);
}
polygen::polygen(const polygen& p) {
    vertices = p.vertices;
}

void polygen::clear() {
    vertices.clear();
}

std::vector<triangle> polygen::triangulate() {
    std::vector<triangle> triangles;
    std::vector<V2D>::iterator it0 = vertices.begin();
    std::vector<V2D>::iterator it1 = it0;
    std::vector<V2D>::iterator it2 = ++it1;
    for (it2 = ++it2; it2 != vertices.end(); ++it1, ++it2)
        triangles.push_back(triangle(*it0, *it1, *it2));
    return triangles;
}

std::set<V2D> polygen::rasterization() {
    std::set<V2D> points;
    std::vector<triangle> triangles = triangulate();
    std::vector<triangle>::iterator it = triangles.begin();
    for (; it != triangles.end(); ++it){
        std::set<V2D> sub_points(it->rasterization());
        points.insert(sub_points.begin(), sub_points.end());
    }
    return points;
}

polygen& polygen::operator = (const polygen& p) {
    vertices = p.vertices;
    return *this;
}

polygen polygen::operator * (float scale) {
    polygen p(*this);
    std::vector<V2D>::iterator it = p.vertices.begin();
    for (; it != p.vertices.end(); ++it)
        *it = *it * scale;
    return p;
}

V2D& polygen::operator [] (int index) {
    return vertices[index];
}

polygen& polygen::scale(float s) {
    std::vector<V2D>::iterator it = vertices.begin();
    for (; it != vertices.end(); ++it)
        it->scale(s);
    return *this;
}

int polygen::size() const {
    return vertices.size(); 
}
