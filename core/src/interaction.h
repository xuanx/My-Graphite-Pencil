/*
 * =====================================================================================
 *
 *       Filename:  interaction.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月28日 15时52分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc 
 *        Company:  ssspace
 *
 * =====================================================================================
 */

#ifndef INTERACTION_H
#define INTERACTION_H

class interaction {

public:    

    void setPaper(const paper& pp);
    void setPencil(const pencil& pn);
    void setBlender(const blender& b);
    void setEraser(const eraser& e);

    void setNpaper(unsigned n);
    void setNpencil(unsigned n);
    void setNblender(unsigned n);
    void setNeraser(unsigned n);

    void rotatePencil(float angle);
    void rotateBlender(float angle);
    void rotateEraser(float angle);

    vector<point> drawing(int x, int y);
    vector<point> erasering(int x, int y);

protected:

    paper   _paper;
    pencil  _pencil;
    blender _blender;
    eraser  _eraser;

    static unsigned nPaper;
    static unsigned nPencil;
    static unsigned nBlender;
    static unsigned nEraser;

    deque<paper>          paperHistory;
    deque<pencil>         pencilHistory;
    deque<blender>        blenderHistory;
    deque<eraser>         eraserHistory;
};

#endif
