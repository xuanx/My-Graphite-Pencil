/*
 * =====================================================================================
 *
 *       Filename:  point.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月30日 14时01分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include "../headers/headers.h"

point::point(float x, float y): V2D(x, y){}
point::point(const point& p): V2D(p), attri(p.attri) {}
point::point(const V2D& v): V2D(v) {}

float& point::operator [] (ATTRI name) {
    return attri[name];
}
float& point::operator [] (AXIS axis) {
    return V2D::operator [] (axis);
}

point& point::operator () (ATTRI name, float value) {
    attri[name] = value;
    return *this;
}

point& point::operator () (AXIS axis, float value) {
    V2D::operator() (axis, value);
    return *this;
}

point& point::operator = (const point& p){
    V2D::operator = (p);
    attri = p.attri;
    return *this;
}
