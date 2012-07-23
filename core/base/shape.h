/* =====================================================================================
 *
 *       Filename:  shape.h
 *
 *    Description:  definition to pencil
 *
 *        Version:  1.0
 *        Created:  2012年06月03日 21时19分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  ssspace
 *
 * ===================================================================================== */
#ifndef SHAPE_H
#define SHAPE_H

class point;

class shape {
public:
    typedef enum attri_shape {C_A, C_C, D_D} ATTRI;

    shape(float cc);
    shape(const shape& p);
    shape();

    shape& operator =  (const shape& p);
    shape& operator *  (float scale);
    shape& operator () (ATTRI name, float value);
    float& operator [] (ATTRI name);
    point& operator [] (int index);

    void setShape(float* pc, const polygen& p);
    void rotate(float d);
    vector<point>& getPolygen();
    int  size();
    float divide(float pressure);

private:    
    void rasterization();

    point                   _center;
    vector<point>           _polygen;
    vector<point>           _area;
    attribute<ATTRI, float> _attri;
};

#endif
