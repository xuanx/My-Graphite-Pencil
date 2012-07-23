/*
 * =====================================================================================
 *
 *       Filename:  slinearSystem.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年07月03日 17时21分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef SOLVE_LINEARSYSTEM_H
#define SOLVE_LINEARSYSTEM_H

#include <vector>

#define M     std::vector<std::vector<MT> >  // matrix
#define V     std::vector<MT>                // column vector of matrix
#define MI    int                            // counter for matrix
#define MRI   std::vector<MI>                // row index of matrix

template<class MT>
class LinearSystem {
public: 
    LinearSystem();
    LinearSystem(const M& m);

    void coefficientWith(const M& m);

    V solutionWith(const V& y);
    V solutionWith(const V& y, const M& m);

    bool hasSolution() { return canPA_LU; }
private:
    void replacement(V& dst, const V& src, MI i);
    bool setPivot(const M& m, MRI& p, MI i);
    void set_P_L_U(const M& m, const MRI& p);
    V M_Multi_V(const M& m, const V& x);
    void PA_LU();
    
    V solutionLowWith(const V& y, const M& m);
    V solutionUpWith(const V& y, const M& m);

    bool canPA_LU;
    // PA = LU : 
    // P:行交换矩阵，A:原始系数矩阵
    // L:下三角矩阵，U:上三角矩阵
    M P;
    M A;
    M L;
    M U;
};

template<class MT>
LinearSystem<MT>::LinearSystem() {}
template<class MT>
LinearSystem<MT>::LinearSystem(const M& m) { coefficientWith(m); }

template<class MT>
void LinearSystem<MT>::coefficientWith(const M& m) {

    MI n = m.size();
    A = m;
    PA_LU();
}

template<class MT>
void LinearSystem<MT>::PA_LU() {// PA = LU

    M   m = A;
    MI  n = A.size();
    MRI p = MRI(n);

    for (MI i = 0; i < n; ++i)
        p[i] = i;

    for (MI i = 0; i < n-1; ++i) {
        if (setPivot(m, p, i))
            for (MI j = i + 1; j < n; ++j) 
                replacement(m[p[j]], m[p[i]], i);
        else {
            canPA_LU = false;
            return;
        }
    }
 
    set_P_L_U(m, p);
    canPA_LU = true;

}

template<class MT>
bool LinearSystem<MT>::setPivot(const M& m, MRI& p, MI i) {

    MT max = m[p[i]][p[i]] < 0 ? -m[p[i]][p[i]] : m[p[i]][p[i]];
    MI n = p.size(), r = i, tmp = p[i];

    for (MI j = i+1; j < n; ++j)
        if (max < m[p[j]][p[i]] || max < -m[p[j]][p[i]]) {
            max = m[p[j]][p[i]] < 0 ? -m[p[j]][p[i]] : m[p[j]][p[i]];
            r   = j;
        }

    p[i] = p[r];
    p[r] = tmp;

    return max != 0;
}

template<class MT>
void LinearSystem<MT>::replacement(V& dst, const V& src, MI i) {

    MT scale = dst[i] / src[i];
    dst[i]   = scale;

    MI n   = dst.size();
    for (i = i + 1; i < n; ++i)
        dst[i] -= src[i] * scale;
}

template<class MT>
void LinearSystem<MT>::set_P_L_U(const M& m, const MRI& p) {

    MI n = m.size();
    P = M(n, V(n));
    L = M(n, V(n));
    U = M(n, V(n));

    for (MI i = 0; i < n; ++i)
        for (MI j = 0; j < n; ++j) {
            P[i][j] = j == p[i] ? 1 : 0;
            L[i][j] = i == j ? 1 : (i < j ? 0 : m[p[i]][j]);
            U[i][j] = i <= j ? m[p[i]][j] : 0;
        }
}

template<class MT>
V LinearSystem<MT>::solutionWith(const V& y, const M& m) {//AX = Y => X

    coefficientWith(m);
    return solutionWith(y);

}


template<class MT>
V LinearSystem<MT>::solutionWith(const V& y) {//AX = Y => X
    if (!canPA_LU)
        return V(y.size());

    V y1 = M_Multi_V(P, y);
    V y2 = solutionLowWith(y1, L);
    return solutionUpWith(y2, U);

}

template<class MT>
V LinearSystem<MT>::M_Multi_V(const M& m, const V& x) {// AX = Y => Y

    MI n = x.size(), i, j;
    V  y = V(n);
    for (i = 0; i < n; ++i) 
        for(y[i]  = 0, j = 0; j < n; ++j)
            y[i] += m[i][j] * x[j];
    return y;
}

template<class MT>
V LinearSystem<MT>::solutionLowWith(const V& y, const M& m) {//LX = Y => X

    MI n = y.size(), i, j;
    V  x = V(n);
    for (i = 0; i < n; ++i) 
        for(x[i]  = y[i], j = 0; j < i; ++j)
            x[i] -= m[i][j] * x[j];
    return x;
}

template<class MT>
V LinearSystem<MT>::solutionUpWith(const V& y, const M& m) {//UX = Y => X

    MI n = y.size(), i, j;
    V  x = V(n);
    for (i = n - 1; i >= 0; --i) {
        for(x[i] = y[i], j = n - 1; j > i; --j)
            x[i] -= m[i][j] * x[j];
        x[i] /= m[i][i];
    }
    return x;
}

#undef M   
#undef V   
#undef MI  
#undef MRI 

#endif

