#include "pictures.h"

picture::picture(int w, int h, QWidget* parent): QWidget(parent) {

    setFixedSize(w, h);
    image = QImage(w, h, QImage::Format_ARGB32);
    image.fill(Qt::white);
    color = Qt::black;

}

picture::~picture() {
    //
}

void picture::drawLine(int x1, int y1, int x2, int y2) {

    painter.begin(&image);
    painter.setPen(color);
    painter.drawLine(x1, y1, x2, y2);
    painter.end();

}

void picture::drawPoint(int x, int y) {

    painter.begin(&image);
    painter.setPen(color);
    painter.drawPoint(x, y);
    painter.end();

}

void picture::drawRect(int x, int y, int w, int h) {

    painter.begin(&image);
    painter.setPen(color);
    painter.drawRect(x, y, w, h);
    painter.end();

}

void picture::showPicture() {

    update();

}

void picture::setSize(int w, int h) {

    setFixedSize(w, h);
    image = QImage(w, h, QImage::Format_ARGB32);
    image.fill(Qt::white);

}

void picture::setColor(const QColor c) {

    color = c;

}

void picture::setAlpha(int alpha) {

    color.setAlpha(alpha);

}

void picture::fillWith(const QColor color) {

    image.fill(color);

}
void picture::paintEvent(QPaintEvent *) {

    painter.begin(this);
    painter.drawImage(0, 0, image);
    painter.end();

}

