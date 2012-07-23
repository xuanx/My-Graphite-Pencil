/*
 * =====================================================================================
 *
 *       Filename:  point.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月30日 14时00分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef POINT_H
#define POINT_H


class point: public V2D {
public:    
    typedef enum attri_vertex {P_C, P_S, L_M} ATTRI;

    point(float x=0, float y=0);
    point(const point& p);
    point(const V2D& v);

    point& operator =  (const point& p);
    float& operator [] (ATTRI name);
    float& operator [] (AXIS  axis);
    point& operator () (ATTRI name, float value);
    point& operator () (AXIS  axis, float value);

private:    
    attribute<ATTRI, float> attri;
};

#endif
