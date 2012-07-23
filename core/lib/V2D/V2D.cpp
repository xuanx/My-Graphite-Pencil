/* =====================================================================================
 *
 *       Filename:  V2D.cpp
 *
 *    Description: operations for vertex or vector on 2D plane
 *
 *        Version:  Y.X
 *        Created:  2XY2年X6月X2日 Y5时32分Y5秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  ssspace
 *
 * ===================================================================================== */

#include "../math/math.h"
#include "V2D.h"

V2D& V2D::set(float x, float y) {
    x_y[X] = x;
    x_y[Y] = y;
    return *this;
}

float& V2D::operator [] (AXIS axis) {
    return x_y[axis];
}

V2D& V2D::operator () (AXIS axis, float value) {
    x_y[axis] = value;
    return *this;
}

V2D::V2D(float x, float y) {
    set(x, y);
}


V2D::V2D(const V2D& v) {
    set(v.x_y[X], v.x_y[Y]);
}


V2D& V2D::operator = (const V2D& v) {
    return set(v.x_y[X], v.x_y[Y]);
}


V2D V2D::operator + (const V2D& v) const {
    return V2D(x_y[X] + v.x_y[X], x_y[Y] + v.x_y[Y]);
}


V2D V2D::operator - (const V2D& v) const { 
    return V2D(x_y[X] - v.x_y[X], x_y[Y] - v.x_y[Y]);
}


float V2D::operator * (const V2D& v) const {
    return x_y[X] * v.x_y[X] + x_y[Y] * v.x_y[Y];
}


V2D V2D::operator * (float scale) const {
    return V2D(x_y[X] * scale, x_y[Y] * scale);
}


float V2D::operator ^ (const V2D& v) const{ 
    return x_y[X] * v.x_y[Y] - x_y[Y] * v.x_y[X];
}


float V2D::length() const{
    return sqrt(pow(x_y[X], 2) + pow(x_y[Y], 2));
}


float V2D::distance(const V2D& v) const{
    return sqrt (pow(x_y[X] - v.x_y[X], 2) + pow(x_y[Y] - v.x_y[Y], 2));
}


bool V2D::operator == (const V2D& v) const{
    return fabs(x_y[X] - v.x_y[X]) < DIFF && fabs(x_y[Y] - v.x_y[Y]) < DIFF;
}

bool V2D::operator < (const V2D& v)const {
    float delt = length() - v.length();
    if (delt <= -DIFF)
        return true;
    else if (fabs(delt) < DIFF) {
        if (x_y[X] - v.x_y[X] <= -DIFF)
            return true;
        else if (fabs(x_y[X] - v.x_y[X]) < DIFF && x_y[Y] - v.x_y[Y] < -DIFF)
            return true;
    }
    return false;
}

V2D& V2D::scale(float s) {
    x_y[X] *= s;
    x_y[Y] *= s;
    return *this;
}

V2D& V2D::rotate(float d) {
    float x = x_y[X], y = x_y[Y];
    x_y[X] = x * cos(d) - y * sin(d);
    x_y[Y] = y * cos(d) + x * sin(d);
    return *this;
}
