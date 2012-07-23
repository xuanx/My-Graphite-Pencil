/*
 * =====================================================================================
 *
 *       Filename:  eraser.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月29日 13时04分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef ERASER_H
#define ERASER_H

class eraser {
public:
    typedef enum attri_eraser {PLR_PTB, P_T, P_A, DRG} ATTRI;

    eraser();

    eraser(const eraser& e);
    eraser& operator =  (const eraser& e);
    eraser& operator () (ATTRI name, float value);
    float&  operator [] (ATTRI name);
    point&  operator [] (int index);
    int size();

    void erasering(int x, int y, paper& pp);
    void sharpen(const shape& p);
    void rotate(float angle);
    shape& getShape() { return sp; }

private:    
    float adjust(float lmr_sum);

    attribute<ATTRI, float> attri;
    shape sp;
};

#endif
