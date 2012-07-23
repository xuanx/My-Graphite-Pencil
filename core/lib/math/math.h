/*
 * =====================================================================================
 *
 *       Filename:  math.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月28日 11时24分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#ifndef MATH_H
#define MATH_H

#include <cmath>

#define DIFF 0.000001
#define P_I  3.14159265358979323846

#define MAX2(a, b) (a > b ? a : b)
#define MIN2(a, b) (a < b ? a : b)

#define MAX3(a, b, c) (a > b ? MAX2(a, c) : MAX2(b, c))
#define MIN3(a, b, c) (a < b ? MIN2(a, c) : MIN2(b, c))

#define MAX4(a, b, c, d) (a > b ? MAX3(a, c, d) : MAX3(b, c, d))
#define MIN4(a, b, c, d) (a < b ? MIN3(a, c, d) : MIN3(b, c, d))

#endif
