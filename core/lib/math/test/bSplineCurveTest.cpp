/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年07月04日 18时03分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <cmath>
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include "../bSplineCurve.h"
using namespace std;

BSpline<GLdouble> bSpline;
GLdouble ox, oy;
vector<GLdouble> X;
vector<GLdouble> Y;
int mstate = 0;

void drawCurve(int pn){
 
    int n = X.size();
    int m = 4;
    if(!bSpline.createBSpline(m, n))
        return;


    /*GLdouble min = 0;
    vector<GLdouble>& knot = bSpline[0];
    knot[0] = min;
    int k1, k2 = n + m / 2;
    for(int i = 0; i < m+n; ++i){
        k1 = i - m / 2;
        if (k1 <= 0)
            knot[i] = 0;
        else if (k1 >= n)
            knot[i] = knot[i-1];
        else {
            GLdouble xx = pow(X[k1] - X[k1-1], 2);
            GLdouble yy = pow(Y[k1] - Y[k1-1], 2);
            knot[i] = knot[i-1] + sqrt(xx + yy);
        }
        cout << knot[i] << endl;
    }
    GLdouble max = knot[m+n-1];*/

    /*GLdouble min = 0;
    vector<GLdouble>& knot = bSpline[0];
    knot[0] = min;
    for(int i = 1; i < m+n; ++i){
        GLdouble xx = pow(X[i] - X[i-1], 2);
        GLdouble yy = pow(Y[i] - Y[i-1], 2);
        knot[i] = knot[i-1] + sqrt(xx + yy);
    }
    GLdouble max = knot[m+n-1];*/

    GLdouble min = 0;
    GLdouble max = 1;//n - m + 1;
    bSpline.setStandardKnot(min, max);
    //GLdouble max = 1;//n + m - 1;
    //bSpline.setUniformKnot(min, max);

    vector<vector<GLdouble> > points(2);
    points[0] = X;
    points[1] = Y;
    //points = bSpline.interpolateWith(points);
    //bSpline.setRange(min, max);

    GLdouble step = (max - min) / (pn-1);
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
        for (GLdouble t = min+step; t <= max; t += step) {
            bSpline.BSplineWith(t);
            GLdouble x = 0, y = 0; 
            GLdouble sum = 0;
            for (int i = 0; i < n; ++i) {
                x += points[0][i] * bSpline[m][i];
                y += points[1][i] * bSpline[m][i];
                sum += bSpline[m][i];
            }
            glVertex2d(x, y);

            /*for (int i = 0; i < n; ++i) {
               glColor3f(1.0 - GLfloat(i) / n, 1.0, 0.0);
               glVertex2f(t * 200, bSpline(m, i) * 200);
            }*/
        }
    glEnd();

}

void drawPoints() {

    glColor3f(1.0, 0.0, 0.0);
    GLfloat sizes[2];
    glGetFloatv(GL_POINT_SIZE_RANGE, sizes);
    glPointSize(sizes[0] + (sizes[1] - sizes[0]) / 10);
    int n = X.size();

    glBegin(GL_POINTS);
    for (int i = 0; i < n; ++i)
        glVertex2f(X[i], Y[i]);
    glEnd();

    glPointSize(sizes[0]);
}


void clearPoints() {
    X.clear();
    Y.clear();
}

void setupRC() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void renderScence() {
    glClear(GL_COLOR_BUFFER_BIT);
    int n = X.size();

    glPushMatrix();
    if (mstate == 1) 
        drawCurve(X.size()*500);
    if (mstate < 2) 
        drawPoints();
    else if (mstate == 2) 
        clearPoints();
    glPopMatrix();

    glutSwapBuffers();
   
}

void mouseEvent(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        /*if(X.empty()) {
            X.push_back(x - ox);
            Y.push_back(oy - y);
        }
        else {
            X.pop_back();
            Y.pop_back();
        }
        X.push_back(x - ox);
        Y.push_back(oy - y);*/

        X.push_back(x - ox);
        Y.push_back(oy - y);
        mstate = 0;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        mstate = 1;
    }
    else if (button == GLUT_MIDDLE_BUTTON) 
        mstate = 2;

    glutPostRedisplay();
}
                                                            
void changeSize(int w, int h) {
  
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    ox = GLfloat(w) / 2;
    oy = GLfloat(h) / 2;

    glOrtho(-w/2, w/2, -h/2, h/2, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}


int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("B-Spine Curve");

    glutReshapeFunc(changeSize);
    glutMouseFunc(mouseEvent);
    glutDisplayFunc(renderScence);

    setupRC();
    glutMainLoop();

    return 0;
}

