/* =====================================================================================
 *
 *       Filename:  V2D.h
 *
 *    Description:  Definite the vertex or vector on 2D plane
 *
 *        Version:  1.0
 *        Created:  2012年06月02日 15时15分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  ssspace
 *
 * ===================================================================================== */


#ifndef VERTEX_H
#define VERTEX_H

class V2D {
public:
    enum AXIS {X, Y};
    V2D(float x=0, float y=0);
    V2D(const V2D& v);

    float& operator [] (AXIS axis);
    V2D&   operator () (AXIS axis, float value);
    V2D&   operator  = (const V2D& v);
    V2D    operator  + (const V2D& v) const;
    V2D    operator  - (const V2D& v) const;
    float  operator  * (const V2D& v) const; // multiply
    V2D    operator  * (float scale ) const; // multiply
    float  operator  ^ (const V2D& v) const; // product
    bool   operator == (const V2D& v) const;
    bool   operator <  (const V2D& v) const;

    V2D&   scale(float s);
    V2D&   rotate(float d);

    float length() const;
    float distance(const V2D& v) const;

private:
    V2D& set(float x, float y);

    float x_y[2];
};

#endif
