/* =====================================================================================
 *
 *       Filename:  line.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月02日 19时14分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  ssspace
 *
 * ===================================================================================== */
#ifndef LINE_H
#define LINE_H

#include "../V2D/V2D.h"

class line {
public:
    line(float a=0, float b=0, float c=0);
    line(const V2D& v1, const V2D& v2);
    line(const line& l);

    line& operator = (const line& l);
    V2D operator ^ (const line& l);
    bool isParallel(const line& l);
    bool set(const V2D& v1, const V2D& v2);

private:    

    float _a, _b, _c; // ax + by + c = 0;
};

#endif
