/*
 * =====================================================================================
 *
 *       Filename:  blender.h
 *
 *    Description:  :
 *
 *        Version:  1.0
 *        Created:  2012年06月29日 13时03分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef BLENDER_H
#define BLENDER_H

class blender {
public:
    typedef enum attri_blender {PLR_PTB, PLR_BTP, COB, P_T, P_A, DRG} ATTRI;

    blender();
    blender(const blender& b);
    blender& operator = (const blender& b);
    ~blender();

    blender& operator () (ATTRI name, float value);
    float&   operator [] (ATTRI name);
    point&   operator [] (int index);

    int size();
   
    void blendering(int x, int y, paper& pp);
    void sharpen(const shape& p);
    void rotate(float angle);

    shape& getShape() { return sp; }

private:    
    void clearBuffer();
    void setBuffer();
    float adjust(float lmr_sum);
    
    float* buffer;
    attribute<ATTRI, float> attri;
    shape sp;
};

#endif
