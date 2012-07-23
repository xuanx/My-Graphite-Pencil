/*
 * =====================================================================================
 *
 *       Filename:  pencil.cpp
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

pencil::pencil() { 
    bitten_sum = 0; 
}
pencil::pencil(const pencil& p) {
    (*this) = p;
}

pencil& pencil::operator = (const pencil& p) {

    bitten_sum = p.bitten_sum;
    sp = p.sp;
    attri = p.attri;
    return *this;
}

void pencil::drawing(int x, int y, paper& pp) {

    bitten(x, y, pp);
    deposited(x, y, pp);

}

int pencil::size() {
    return sp.size();
}

void pencil::sharpen(const shape& p) {
    sp = p;
    attri[P_A] = sp.divide(attri[P_T]);
    attri[D_D] = sp[shape::D_D];
    attri[DGR] = 0;
}

pencil& pencil::operator () (ATTRI name, float value) {
    attri[name] = value;
    return *this;
}

float& pencil::operator [] (ATTRI name) {
    return attri[name];
}

point& pencil::operator [] (int index) {
    return sp[index];
}

float pencil::da() {
    return 0.5 * attri[P_D];
}
float pencil::ba() {
    return 0.5;
}

float pencil::adjust() {

    return 1 + bitten_sum / sp.size() * 0.5;

}


void pencil::bitten(int x, int y, paper& pp) {

    int psize = sp.size();
    for (int i = 0; i < psize; ++i) {
        grain& g = pp(x+sp[i][point::X], y+sp[i][point::Y]);

        float h_max  = g.h_max(),  h_min  = g.h_min();
        float hp_max = g.hp_max(), hp_min = g.hp_min(), hp_sum = g.hp_sum();

        g[grain::D_L] = h_max - h_max * attri[P_A];
        if (g[grain::D_L] < h_min) g[grain::D_L] = h_min;

        g[grain::T_V] = h_max == h_min ? pp[paper::F_S] : pp[paper::F_V] * g.v_g();

        if (hp_max - hp_min < DIFF)
            g[grain::B_V] = 0;
        else if (h_min >= g[grain::D_L])
            g[grain::B_V] = g[grain::T_V];
        else
            g[grain::B_V] =  ba() * g[grain::T_V] * (hp_sum - g[grain::D_L]) / (hp_max - hp_min);
        //if (g[grain::B_V] < 0) g[grain::B_V] = 0;

    }
}

void pencil::deposited(int x, int y, paper& pp){
    int psize = sp.size();

#include <iostream>
using namespace std;
    //cout << "____________________________(" << x << ", " << y << "):\n";

    for (int i = 0; i < psize; ++i) {

        grain& g0 = pp(x+sp[i][point::X],   y+sp[i][point::Y]);
        grain& g1 = pp(x+sp[i][point::X]-1, y+sp[i][point::Y]);
        grain& g2 = pp(x+sp[i][point::X],   y+sp[i][point::Y]-1);
        grain& g3 = pp(x+sp[i][point::X]-1, y+sp[i][point::Y]-1);

        float h = g0[grain::H];
        float dk0 = g0.d_k(h), dk1 = g1.d_k(h), dk2 = g2.d_k(h), dk3 = g3.d_k(h);
       
        g0[grain::L_K] = g0[grain::T_V] * dk0 + g1[grain::T_V] * dk1 
                       + g2[grain::T_V] * dk2 + g3[grain::T_V] * dk3 ;

        g0[grain::B_K] = g0[grain::B_V] * dk0 + g1[grain::B_V] * dk1 
                       + g2[grain::B_V] * dk2 + g3[grain::B_V] * dk3 ;
        if (g0[grain::T_K] >= g0[grain::L_K])
            g0[grain::B_K] = pow(pp[paper::P_M], attri[P_T]) * g0[grain::B_K];

        g0[grain::T_K] = g0[grain::B_K] * attri[G_P]
                       + g0[grain::B_K] * attri[W_P]
                       + g0[grain::B_K] * attri[C_P];


        g0[grain::L_M] = 1 - g0[grain::T_K] * attri[G_P] / (pp[paper::F_S] + pp[paper::F_V]);
        g0[grain::L_M] = g0[grain::L_M] < 0 ? 0 : (g0[grain::L_M] > 1 ? 1 : g0[grain::L_M]);
        //cout << g0[grain::L_M] << "\t";

        //cout << "(" << x+sp[i][point::X] << ", " << y+sp[i][point::Y] << ", " << h << ", " << g0[grain::L_M] << ")\n";

        g0[grain::H]  -= g0[grain::D_L] * da() * pp[paper::P_W];
        if (g0[grain::H] < 0) g0[grain::H] = 0;
        bitten_sum += g0[grain::B_K];
    }
    //cout <<  endl;

    //sp * adjust();

}

void pencil::rotate(float angle) {
    float d =  P_I * (angle - attri[DGR]) / 180;
    attri[DGR] = angle;
    sp.rotate(d);
}

