/* =====================================================================================
 *
 *       Filename:  pencil.h
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
#ifndef PENCIL_H
#define PENCIL_H

class pencil {
public:    

    typedef enum attri_pencil {G_P, C_P, W_P, P_D, P_T, P_A, D_D, DGR} ATTRI;

    pencil();
    pencil(const pencil& p);

    pencil& operator =  (const pencil& p);
    pencil& operator () (ATTRI name, float value);
    float&  operator [] (ATTRI name);
    point&  operator [] (int i);

    void drawing(int x, int y, paper& pp);
    void rotate(float angle);
    void sharpen(const shape& p);
    int  size();
    shape& getShape() { return sp; }

private:

    void bitten(int x, int y , paper& pp);
    void deposited(int x, int y, paper& pp);

    float da(); 
    float ba();
    float adjust();

    attribute<ATTRI, float> attri;
    shape                   sp;
    float                   bitten_sum;
};

#endif
