/*
 * =====================================================================================
 *
 *       Filename:  eraser.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月29日 13时04分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include "../headers/headers.h"

eraser::eraser() {}

eraser::eraser(const eraser& e) {
    (*this) = e;
}

eraser& eraser::operator = (const eraser& e) {
    sp    = e.sp;
    attri = e.attri;
    return *this;
}

eraser& eraser::operator () (ATTRI name, float value) {
    attri[name] = value;
    return *this;
}

float& eraser::operator [] (ATTRI name) {
    return attri[name];
}

point& eraser::operator [] (int index) {
    return sp[index];
}

int eraser::size() {
    return sp.size();
}

float eraser::adjust(float lmr_sum) {
    return 1 + lmr_sum / sp.size() * 0.5;
}

void eraser::erasering(int x, int y, paper& pp) {
    float lmr_sum = 0;
    int size = sp.size();

    using namespace std;
    //cout << "----------in ==== erasering  \n";
    for (int i = 0; i < size; ++i) {
        int dx = x + sp[i][point::X], dy = y + sp[i][point::Y];

        //cout << "(" << dx << ", " << dy << ", " << pp(dx, dy)[grain::L_M];
        float lmr = pp(dx, dy)[grain::L_M] * sp[i][point::P_S] * attri[PLR_PTB];
        pp(dx, dy)[grain::L_M] -= lmr;
        //cout << ", " << pp(dx, dy)[grain::L_M] << ")\n";

        lmr_sum += lmr;
    }
    //sp * adjust(lmr_sum);
}

void eraser::sharpen(const shape& p) {
    sp = p;
    attri[P_A] = sp.divide(attri[P_T]);
}

void eraser::rotate(float angle) {
    float d = P_I * (angle - attri[DRG]) / 180;
    attri[DRG] = angle;
    sp.rotate(d);
}
