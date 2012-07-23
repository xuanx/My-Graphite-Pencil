#include "canvas.h"

canvas::canvas(int w, int h, QWidget* parent): picture(w, h, parent) {

    aType = NONE;
}

void canvas::setActionType(AT t) {

    aType = t;

}

void canvas::action(int x, int y) {

    vector<point>  drawArea;

    if (aType == DRAW)
        drawArea = drawing(x, y);
    else if (aType == ERASE)
        drawArea = erasering(x, y);
    else if (aType == NONE)
        return;

    using namespace std;
    int n = drawArea.size();
    for (int i = 0; i < n; ++i) {
        float alpha =  drawArea[i][point::L_M] < 0 ? 0 :
                    (drawArea[i][point::L_M] > 1 ? 1 : drawArea[i][point::L_M]);
        int gray = 255 - int(alpha * 255);
        cout << gray <<  endl;
        setColor(QColor(gray, gray, gray));
        drawPoint(drawArea[i][point::X]+x, drawArea[i][point::Y]+y);
    }
    showPicture();
}

void canvas::mouseMoveEvent(QMouseEvent *event) {

    if (event->buttons() & Qt::LeftButton)
            action(event->x(), event->y());
}

/*
void canvas::dealPaperRequire() {

    emit sendPaperInfo(_paper[paper::W],
                       _paper[paper::H],
                       _paper[paper::P_W],
                       _paper[paper::P_M],
                       _paper[paper::F_S],
                       _paper[paper::F_V]);

}


void canvas::dealPencilRequire() {

    emit sendPencilInfo(_pencil[pencil::G_P],
                        _pencil[pencil::C_P],
                        _pencil[pencil::W_P],
                        _pencil[pencil::P_D],
                        _pencil[pencil::P_T],
                        _pencil[pencil::DRG],
                        _pencil.getShape());

}

void canvas::dealBlenderRequire() {

    emit sendBlenderInfo(_blender[blender::PLR_PTB],
                        _blender[blender::PLR_BTP],
                        _blender[blender::COB],
                        _blender[blender::P_T],
                        _blender[blender::DRG],
                        _blender.getShape());

}

void canvas::dealEraserRequire() {

    emit sendEraserInfo(_eraser[eraser::PLR_PTB],
                        _eraser[eraser::P_T],
                        _eraser[eraser::DRG],
                        _eraser.getShape());

}
*/

void canvas::setPaper(const paper &pp) {

    interaction::setPaper(pp);
    setSize(int(_paper[paper::W]), int(_paper[paper::H]));
    fillWith(Qt::white);

}

void canvas::setPencil(const pencil &pn) {

    interaction::setPencil(pn);

}

void canvas::setBlender(const blender &b) {

    interaction::setBlender(b);

}

void canvas::setEraser(const eraser &e) {

    interaction::setEraser(e);

}
