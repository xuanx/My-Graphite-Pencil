/*
 * =====================================================================================
 *
 *       Filename:  bSpline.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年07月04日 14时06分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef BSPLINECURVE_H
#define BSPLINECURVE_H

#include <vector>
#include "linearSystem.h"

#define V std::vector<BT>
#define B std::vector<std::vector<BT> >

template<class BT>
class BSpline {
public:    
    BSpline();
    bool createBSpline(int m, int n);
    void BSplineWith(BT t);
    void setStandardKnot(BT min=0, BT max=1);
    void setUniformKnot(BT min=0, BT max=1);
    void setRange(BT& min, BT& max);

    B interpolateWith(const B& src);

    BT   operator () (int m, int k) { return bSpline[m][k]; }
    V&   operator [] (int m) { return bSpline[m]; }

private:    
    B bSpline;
    int _m;
    int _n;
};

template<class BT>
BSpline<BT>::BSpline() {
    _m = _n = 0;
}

template<class BT>
void BSpline<BT>::setRange(BT& min, BT& max) {
    min = bSpline[0][_m/2];
    max = bSpline[0][_n+_m/2-1];
}

template<class BT>
void BSpline<BT>::setStandardKnot(BT min, BT max) {

    int size = _n + _m;
    BT  step = (max - min) / (_n - _m + 1);
    for (int k = 0; k < size ; ++k)
        bSpline[0][k] = (k < _m ? min : (k > _n ? max : bSpline[0][k-1] + step));
}

template<class BT>
void BSpline<BT>::setUniformKnot(BT min, BT max) {
    
    int size = _m + _n;
    BT  step = (max - min) / (_n + _m - 1);
    bSpline[0][0] = min;
    for (int i = 1; i < size ; ++i)
        bSpline[0][i] = bSpline[0][i-1] + step;
}

template<class BT>
bool BSpline<BT>::createBSpline(int m, int n) {
    if (n < 3 || n < m)
        return false;
    _m = m;
    _n = n;

    bSpline = B(m + 1);
    for (int i = m, k = n; i >= 0; --i, ++k) 
        bSpline[i] = V(k);

    return true;
}

template<class BT>
void BSpline<BT>::BSplineWith(BT t) {

    int nk = bSpline[1].size();
    for (int k = 0; k < nk; ++k) 
        bSpline[1][k] = bSpline[0][k] < t && t <= bSpline[0][k+1] ? 1.0 : 0.0;

    for (int m = 2; m <= _m; ++m) {
        
        int ks = bSpline[m].size();
        for (int k = 0; k < ks; ++k){
            bSpline[m][k] = 0;

            BT denom = bSpline[0][k+m-1] - bSpline[0][k];
            if (denom != 0)
                bSpline[m][k] = (t - bSpline[0][k]) * bSpline[m-1][k] / denom;
            
            denom = bSpline[0][k+m] - bSpline[0][k+1];
            if (denom != 0)
                bSpline[m][k] += (bSpline[0][k+m] - t) * bSpline[m-1][k+1] / denom;

            //BT denom = bSpline[0][k+m] - bSpline[0][k];
            //if (denom != 0)
            //    bSpline[m][k] = ((t - bSpline[0][k]) * bSpline[m-1][k] +
            //                     (bSpline[0][k+m] - t) * bSpline[m-1][k+1]) / denom;

        }
    }
}


template<class BT>
B BSpline<BT>::interpolateWith(const B& src) {

    B coe(_n, V(_n));
    int begin = _m / 2;

    for (int i = 0; i < _n; ++i) {
        BSplineWith(bSpline[0][i+begin]);
        for (int j = 0; j < _n; ++j) 
            coe[i][j] = bSpline[_m][j];
    }

    LinearSystem<BT> ls(coe);
    if (!ls.hasSolution())
        return src;
    int n = src.size();
    B dst = B(n);

    for (int i = 0; i < n; ++i) 
       dst[i] = ls.solutionWith(src[i]);
 
    return dst;
}

#undef V
#undef B

#endif
