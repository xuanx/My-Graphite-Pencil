/* =====================================================================================
 *
 *       Filename:  triangle.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月02日 18时59分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  ssspace
 *
 * ===================================================================================== */
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <set>
#include "../V2D/V2D.h"

class triangle {
public:    
    enum VERTEX {A, B, C};
    triangle();
    triangle(const V2D& v1, const V2D& v2, const V2D& v3);
    triangle(const triangle& t);

    triangle& operator = (const triangle& t);
    V2D& operator [](VERTEX vertex);
    bool isInner(const V2D& v);
    std::set<V2D> rasterization();

    triangle& scale(float s);
private:
    void set(const V2D& v1, const V2D& v2, const V2D& v3);
    V2D vertex[3];
};

#endif
