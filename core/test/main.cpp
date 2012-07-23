/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年07月17日 20时58分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include "headers/headers.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    V2D         ps[4] = {V2D(2,2), V2D(-2,2), V2D(-2,-2), V2D(2,-2)};
    float       pc[4] = {0.5, 0.5, 0.5, 0.5};
    polygen     po(ps, ps+4);
    shape       sp(1);
    sp.setShape(pc, po);


    pencil      pen;
    pen(pencil::G_P, 0.8)(pencil::C_P, 0.1)(pencil::W_P, 0.08)(pencil::P_T, 0.97)(pencil::P_D, 0.8);
    pen.sharpen(sp);

    blender     bn;
    bn(blender::PLR_PTB, 0.7)(blender::PLR_BTP, 0.5)(blender::COB, 0.5)(blender::P_T, 0.8);
    bn.sharpen(sp);

    eraser      es;
    es(eraser::PLR_PTB, 0.7)(eraser::P_T, 0.7);
    es.sharpen(sp);


    paper       pp;
    pp(paper::P_W, 0.5)(paper::F_S, 500.0)(paper::F_V, 2000.0);
    int w = 100, h = 100;
    srand(time(0));
    float** gs = new float*[w];
    for (int i = 0; i < w; ++i) {
        gs[i] = new float[h];
        for (int j = 0; j < h; ++j)
            gs[i][j] = rand() / float(RAND_MAX);
    }
    pp.init(w, h, gs);

    int n = sp.size();
    for (int i = 0; i < n; ++i) 
        cout << "(" << sp[i][point::X] << ", " << sp[i][point::Y] << ", " << sp[i][point::P_C]<< ")\n";
    cout << "shape--n: "  << n << endl;

    n = pen.size();
    for (int i = 0; i < n; ++i) 
        cout << "(" << pen[i][point::X] << ", " << pen[i][point::Y] << ")\n";
    cout << "pen--n: "  << n << endl;
/*  
    n = bn.size();
    for (int i = 0; i < n; ++i) 
        cout << "(" << bn[i][point::X] << ", " << bn[i][point::Y] << ")\n";
    cout << "bn--n: "  << n << endl;

    n = es.size();
    for (int i = 0; i < n; ++i) 
        cout << "(" << es[i][point::X] << ", " << es[i][point::Y] << ")\n";
    cout << "es--n: "  << n << endl;
*/

    pen.drawing(50, 50, pp);
    cout << "_____________________________________________________\n";
    bn.blendering(50, 50, pp);

    interaction actor;
    actor.setPaper(pp);
    actor.setPencil(pen);
    actor.setBlender(bn);
    actor.setEraser(es);


    return 0;
}
