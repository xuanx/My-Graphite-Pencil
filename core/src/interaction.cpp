/*
 * =====================================================================================
 *
 *       Filename:  interaction.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月28日 15时53分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  ssspace
 *
 * =====================================================================================
 */

#include "../headers/headers.h"

unsigned interaction::nPaper  = 20;
unsigned interaction::nPencil  = 20;
unsigned interaction::nBlender = 20;
unsigned interaction::nEraser  = 20;

vector<point> interaction::drawing(int x, int y) {

    _pencil.drawing(x, y, _paper);
    _blender.blendering(x, y, _paper);

    /*
    set<point> points;

    int n = _pencil.size();
    for (int i = 0; i < n; ++i)
        points.insert(_pencil[i]);
    n = _blender.size();
    for (int i = 0; i < n; ++i)
        points.insert(_blender[i]);


    set<point>::iterator it = points.begin();
    for (int i = 0; it != points.end(); ++it, ++i) {
        point pt = *it;
        pt[point::L_M] =  _paper(pt[point::X]+x, pt[point::Y]+y)[grain::L_M];
        drawArea.push_back(pt);

    }
    int n = _pencil.size();
    vector<point> drawArea(n);
    for (int i = 0; i < n; ++i) {
        _pencil[i][point::L_M] = _paper(_pencil[i][point::X]+x, _pencil[i][point::Y]+y)[grain::L_M];
        drawArea[i] = _pencil[i];
    }*/
    int n = _blender.size();
    vector<point> drawArea(n);
    for (int i = 0; i < n; ++i) {
        _blender[i][point::L_M] = _paper(_blender[i][point::X]+x, _blender[i][point::Y]+y)[grain::L_M];
        drawArea[i] = _blender[i];
    }
    return drawArea;

}

vector<point> interaction::erasering(int x, int y) {
    _eraser.erasering(x, y, _paper);

    vector<point> drawArea;
    int n = _eraser.size();
    for (int i = 0; i < n; ++i) {
        point pt = _eraser[i];
        pt[point::L_M] = _paper(pt[point::X]+x, pt[point::Y]+y)[grain::L_M];
        drawArea.push_back(pt);
    }
    return drawArea;

}

void interaction::setPaper(const paper& pp) {

    _paper = pp;
    if (paperHistory.size() >= nPaper)
        paperHistory.pop_front();
    paperHistory.push_back(pp);
}

void interaction::setPencil(const pencil& pn) {
    _pencil = pn;
    if (pencilHistory.size() >= nPencil)
        pencilHistory.pop_front();
    pencilHistory.push_back(pn);

}

void interaction::setBlender(const blender& b) {
    _blender = b;
    if (blenderHistory.size() >= nBlender)
        blenderHistory.pop_front();
    blenderHistory.push_back(b);
}

void interaction::setEraser(const eraser& e) {
    _eraser = e;
    if (eraserHistory.size() >= nEraser)
        eraserHistory.pop_front();
    eraserHistory.push_back(e);
}

void interaction::rotatePencil(float angle) {
    _pencil.rotate(angle);
}

void interaction::rotateBlender(float angle) {
    _blender.rotate(angle);
}

void interaction::rotateEraser(float angle) {
    _eraser.rotate(angle);
}

void interaction::setNpaper(unsigned n) {
    nPaper = n;
}

void interaction::setNblender(unsigned n) {
    nBlender = n;
}
void interaction::setNpencil(unsigned n) {
    nPencil = n;
}
void interaction::setNeraser(unsigned n) {
    nEraser = n;
}

