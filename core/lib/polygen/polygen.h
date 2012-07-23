/* =====================================================================================
 *
 *       Filename:  polygen.h
 *
 *    Description:  Definite polygen on 2D plane
 *
 *        Version:  1.0
 *        Created:  2012年06月02日 18时00分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xxspc
 *        Company:  ssspace
 *
 * ===================================================================================== */
#ifndef POLYGEN_H
#define POLYGEN_H


#include <vector>
#include <set>
#include "../V2D/V2D.h"
#include "../triangle/triangle.h"

class polygen {
public:
    polygen();
    polygen(const V2D* fst, const V2D* lst);
    polygen(const polygen& p);

    std::vector<triangle> triangulate();
    std::set<V2D> rasterization();
    polygen& operator = (const polygen& p);
    polygen operator * (float scale);
    V2D& operator [] (int index);
    void clear();

    polygen& scale(float s);
    int size() const;
private:    
    std::vector<V2D> vertices;

};

#endif
