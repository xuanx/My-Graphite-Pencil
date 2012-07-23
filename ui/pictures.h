#ifndef PICTURES_H
#define PICTURES_H

#include <QWidget>
#include <QImage>
#include <QColor>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>

class picture: public QWidget {

public:
    picture(int w=2, int h=2, QWidget* parent=0);
    ~picture();

    void drawLine(int x1, int y1, int x2, int y2);
    void drawPoint(int x, int y);
    void drawRect(int x, int y, int w, int h);
    void showPicture();
    void setSize(int w, int h);
    void setColor(const QColor c);
    void setAlpha(int alpha);
    void fillWith(const QColor c);

protected:
    void paintEvent(QPaintEvent *);

private:
    QImage image;
    QColor color;
    QPainter painter;
};


#endif // PICTURES_H
