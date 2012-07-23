#ifndef CANVAS_H
#define CANVAS_H

#include "../core/headers/headers.h"
#include "pictures.h"


class canvas: public picture, public interaction {
    Q_OBJECT

public:
    typedef enum action_type {DRAW, ERASE, NONE} AT;

    canvas(int w=2, int h=2, QWidget* parent=0);

signals:
    /*
    void sendPaperInfo(int w2, int h2, float pw2, float pm2, int fs2, int fv2);
    void sendPencilInfo(float G_P, float C_P, float W_P, float P_D, float P_T, float DRG, shape& sp);
    void sendBlenderInfo(float PLR_PTB, float PLR_BTP, float COB, float P_T, float DRG, shape& sp);
    void sendEraserInfo(float PLR_PTB, float P_T, float DRG, shape& sp);
    */

public slots:

    /*
    void dealPaperRequire();
    void dealPencilRequire();
    void dealBlenderRequire();
    void dealEraserRequire();
    */

    void setActionType(canvas::AT t);

    void setPaper(const paper &pp);
    void setPencil(const pencil &pn);
    void setBlender(const blender &b);
    void setEraser(const eraser &e);

protected:
    void action(int x, int y);

    void mouseMoveEvent(QMouseEvent *);

private:
    AT             aType;
};

#endif // CANVAS_H
