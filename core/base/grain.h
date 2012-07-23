/*
 * =====================================================================================
 *
 *       Filename:  grain.h
 *
 *    Description:  definition of grain on paper
 *
 *        Version:  1.0
 *        Created:  2012年06月15日 22时35分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  ssspace
 *
 * =====================================================================================
 */

#ifndef GRAIN_H
#define GRAIN_H

class paper;

class grain {
public:    
    typedef enum attri_grain {
        H, D_L, B_V, B_K, T_K, V_G, T_V, L_K, L_M
    } ATTRI;

private: 
    attribute<ATTRI, float> attri;
    V2D position;
    paper* parent;


public:
    grain();
    grain(const grain& g);
    grain& operator = (const grain& g);

    void init(int x, int y, paper* p);
    grain& operator () (ATTRI name, float value);
    float& operator [] (ATTRI name);
    float& operator [] (V2D::AXIS axis);

    float h_max();
    float h_min();
    float h_sum();

    float hp();
    float hp_max();
    float hp_min();
    float hp_sum();

    float v_g();
    float d_k(float h);

};

#endif
