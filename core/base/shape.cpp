/*
 * =====================================================================================
 *
 *       Filename:  shape.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月04日 00时00分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include "../headers/headers.h"


shape::shape() {}
shape::shape(float cc) {
    _attri[C_C] = cc;
}
shape::shape(const shape& p) { operator = (p);}

shape& shape::operator = (const shape& p) {
    _area    = p._area;
    _attri   = p._attri;
    _center  = p._center;
    _polygen = p._polygen;
    return *this;
}

shape& shape::operator * (const float scale) {
    int n = _polygen.size();
    for (int i = 0; i < n; ++i) {
        _polygen[i][point::X]   *= scale;
        _polygen[i][point::Y]   *= scale;
        _polygen[i][point::P_C] /= scale;
    }

    rasterization();
    return *this;
}

shape& shape::operator () (ATTRI name, float value) {
    _attri[name] = value;
    return *this;
}
point& shape::operator [] (int index) {
    return _area[index];
}

float& shape::operator [] (ATTRI name) {
    return _attri[name];
}
int shape::size() {
    return _area.size();
}

vector<point>& shape::getPolygen() {

    return _polygen;

}

void shape::setShape(float* pc, const polygen& p) {

    _polygen.clear();
    polygen& py = const_cast<polygen&>(p);
    int n = py.size();
    float x_max=py[0][point::X];
    float x_min=py[0][point::X];
    float y_max=py[0][point::Y];
    float y_min=py[0][point::Y];
        
    for (int i = 0; i < n; ++i) {
        _polygen.push_back(py[i]);
        _polygen[i][point::P_C] = pc[i];
        if (x_min > _polygen[i][point::X])
            x_min = _polygen[i][point::X];
        if (x_max < _polygen[i][point::X])
            x_max = _polygen[i][point::X];

        if (y_min > _polygen[i][point::Y])
            y_min = _polygen[i][point::Y];
        if (y_max < _polygen[i][point::Y])
            y_max = _polygen[i][point::Y];
    }
    _center = point((x_min + x_max)/2, (y_min + y_max)/2);
    _center[point::P_C] = _attri[C_C];

    float xlen = x_max - x_min, ylen = y_max - y_min;
    _attri[D_D] = xlen < ylen ? xlen : ylen;
    rasterization();
}


void shape::rasterization() {
    _area.clear();
    set<V2D> area;

    float c_sum = 0;
    int end = _polygen.size();
    for (int i = 0, j = 1; i < end; ++i, ++j) {
        if (j == end) j = 0;

        line l;
        if(!l.set(_polygen[i], _polygen[j])) continue;

        float d1 = _polygen[i].distance(_polygen[j]);

        triangle t(_center, _polygen[i], _polygen[j]);
        set<V2D> points = t.rasterization();
        for(set<V2D>::iterator it = points.begin(); it != points.end(); ++it) {

            line l2;
            if (!l2.set(_center, *it)) {
                if (area.insert(_center).second) {
                    c_sum += _center[point::P_C];
                    _area.push_back(_center);
                }
                continue;
            }
            V2D intersection = l ^ l2;

            float d2 = _polygen[i].distance(intersection);
            float c = d1 < DIFF ? _polygen[i][point::P_C] : 
                      d2 / d1 * (_polygen[j][point::P_C] - _polygen[i][point::P_C]) + _polygen[i][point::P_C];

            d1 = _center.distance(intersection);
            d2 = _center.distance(*it);
            c  = d1 < DIFF ? _center[point::P_C] : d2 / d1 * (c - _center[point::P_C]) + _center[point::P_C];
            point p(*it);
            p(point::P_C, c);

            if (area.insert(p).second) {
                c_sum += c;
                _area.push_back(p);
            }
        }
    }
    _attri[C_A] = c_sum / _area.size();
}

float shape::divide(float pressure) {
    float p_sum = 0;
    int n = size();
    for (int i = 0; i < n; ++i) {
        (*this)[i][point::P_S] = (*this)[i][point::P_C] * pressure;
        p_sum += (*this)[i][point::P_S];
    }
    return p_sum / n;
}

void shape::rotate(float d) {
    int n = size();
    for (int i = 0; i < n; ++i)
        (*this)[i].rotate(d);
}

