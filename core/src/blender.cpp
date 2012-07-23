/*
 * =====================================================================================
 *
 *       Filename:  blender.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月29日 13时04分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include "../headers/headers.h"

blender::blender() {
    buffer = NULL;
}

blender::blender(const blender& b) {

    buffer = NULL;
    (*this) = b;
}

blender& blender::operator = (const blender& b) {

    sp = b.sp;
    attri = b.attri;
    setBuffer();

    return *this;
}

blender::~blender() {
    clearBuffer();
}

void blender::clearBuffer() {
    if (buffer != NULL)
        delete[] buffer;
}

void blender::setBuffer() {

    clearBuffer();
    int n = sp.size();
    buffer = new float[n];
    for (int i = 0; i < n; ++i) 
        buffer[i] = 0;
    
}

int blender::size() {
    return sp.size();
}

void blender::sharpen(const shape& p) {
    sp = p;
    attri[P_A] = sp.divide(attri[P_T]);
    setBuffer();
}

blender& blender::operator () (ATTRI name, float value) {
    attri[name] = value;
    return *this;
}

float& blender::operator [] (ATTRI name) {
    return attri[name];
}

float blender::adjust(float lmr_sum) {
    return 1 + lmr_sum / sp.size() * 0.5;
}
point& blender::operator [] (int index) {
    return sp[index];
}

void blender::blendering(int x, int y, paper& pp) {
    float lmr_sum = 0;

    using namespace std;
    //cout << "----------in ==== blendering  \n";
    int size = sp.size();
    for (int i = 0; i < size; ++i) {
        int dx = x + sp[i][point::X], dy = y + sp[i][point::Y];

        //cout << pp(dx, dy)[grain::L_M] << "=" << buffer[i];//////cout

        float lmr = pp(dx, dy)[grain::L_M] * sp[i][point::P_S] * attri[PLR_PTB];
        pp(dx, dy)[grain::L_M] -= lmr;
        buffer[i]              += lmr;

        //cout << "=" << lmr;//////cout

        lmr_sum += lmr;

        //cout << "=" << pp(dx, dy)[grain::L_M];//////cout

        lmr = buffer[i] * sp[i][point::P_S] * attri[PLR_BTP] * attri[COB];
        buffer[i]              -= lmr;

        //cout << "=" << lmr << "=" << buffer[i];//////cout

        pp(dx, dy)[grain::L_M] += lmr;
        pp(dx, dy)[grain::L_M] = pp(dx, dy)[grain::L_M] < 0 ? 0 : (pp(dx, dy)[grain::L_M] > 1 ? 1 : pp(dx, dy)[grain::L_M]);

        //cout << "=" << pp(dx, dy)[grain::L_M] << "\n";//////cout

    }
    //sp * adjust(lmr_sum);
}

void blender::rotate(float angle) {
    float d = P_I * (angle - attri[DRG]) / 180;
    attri[DRG] = angle;
    sp.rotate(d);
}
