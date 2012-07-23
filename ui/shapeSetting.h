#ifndef SHAPESETTING_H
#define SHAPESETTING_H

#include "../core/headers/headers.h"
#include "pictures.h"

#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QVector>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>



class drawShape: public picture{

    Q_OBJECT
public:
    drawShape(int w=200, int h=200, QWidget* parent=0);
    void clear();

signals:
    void sendPoint(float x, float y);
    void finished(bool);

protected:
    void mousePressEvent(QMouseEvent *);

private:
    int x1, y1, x2, y2;
    int ox, oy;

};

class shapeSetting: public QWidget {

    Q_OBJECT

    struct item {
        QLabel         *axis;
        QDoubleSpinBox *coe;
        float          x, y;
    };

public:
    shapeSetting(QWidget *parent=0);
    ~shapeSetting();
    shape& createShape();

signals:
    //void sendShape(const shape& p);
    void finished(bool);
    void valueChanged(bool);
    void sizeChanged();


public slots:
    void clear();
    void reSet();
    void valueChanged();
    void available(bool);
    void addItem(float x, float y, float c=0.5);
    //void enableReset();

private:

    void initConnect();

    float         scalev;
    shape         sp;
    drawShape     *drawArea;

    QDoubleSpinBox*pc;
    QLabel        *pcTxt;

    QDoubleSpinBox*scale;
    QLabel        *scaleTxt;

    QPushButton   *cancel;
    //QPushButton *apply;
    QPushButton   *reset;

    QGridLayout   *mainLayout;

    QVector<item*> points;
};


#endif // SHAPESETTING_H
