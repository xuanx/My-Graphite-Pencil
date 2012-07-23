/*
 * =====================================================================================
 *
 *       Filename:  paper.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月28日 14时58分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  sspace
 *
 * =====================================================================================
 */

#include "../headers/headers.h"

paper::paper() {

    grains = NULL;
}

paper::paper(const paper& p) {

    grains = NULL;
    (*this) = p;
}

paper& paper::operator = (const paper& p) {

    clear();
    attri = p.attri;

    paper& tmp = const_cast<paper&>(p);
    grains = new grain*[int(tmp[W])];
    for (int x = 0; x < tmp[W]; ++x) {
        grains[x] = new grain[int(tmp[H])];
        for (int y = 0; y < tmp[H]; ++y)
            grains[x][y][grain::H] = tmp(x, y)[grain::H];
    }

    connect();
    return *this;
}

paper::~paper() {
    if (grains != NULL)
        clear();
}

void paper::clear() {
    if (grains != NULL) {
        for (int x = 1; x < attri[W] - 1; ++x)
            delete[] grains[x];
        delete[] grains;
        grains = NULL;
    }
    //attri.clear();
}

void paper::init(int w, int h, float** p) {
    if (grains == NULL)
        clear();

    grains = new grain*[w];
    for (int x = 0; x < w; ++x) {
        grains[x] = new grain[h];
        for (int y = 0; y < h; ++y)
            grains[x][y][grain::H] = p[x][y];
    }

    attri[W] = w;
    attri[H] = h;
    connect();
   
}

void paper::connect() {
    for (int x = 0; x < attri[W]; ++x)
        for (int y = 0; y < attri[H]; ++y) 
            grains[x][y].init(x, y, this);
}

float& paper::operator [] (ATTRI name) {

    return attri[name];
}

grain& paper::operator () (int x, int y) {
    int gx = x < 0 ? 0 : (x < attri[W] ? x : attri[W] - 1);
    int gy = y < 0 ? 0 : (y < attri[H] ? y : attri[H] - 1);

    return grains[gx][gy];
}

paper& paper::operator () (ATTRI name, float value) {

    attri[name] = value;
    return *this;
}


