/*
 * =====================================================================================
 *
 *       Filename:  paper.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年06月28日 14时58分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxpsc
 *        Company:  ssspace
 *
 * =====================================================================================
 */

#ifndef PAPER_H
#define PAPER_H

class paper {
public:
    typedef enum attri_paper {W, H, P_W, P_M, F_S, F_V} ATTRI;
    paper();
    paper(const paper& p);
    paper& operator = (const paper& p);
    ~paper();
    void init(int w, int h, float** p);
    void clear();

    float& operator [] (ATTRI name);
    paper& operator () (ATTRI name, float value);
    grain& operator () (int x, int y);

private:
    void connect();

    grain** grains;
    attribute<ATTRI, float> attri;

};

#endif
