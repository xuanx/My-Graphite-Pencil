#ifndef ERASERSETTING_H
#define ERASERSETTING_H

#include "../core/headers/headers.h"
#include "shapeSetting.h"

class eraserSetting: public QWidget {
    Q_OBJECT
public:
    eraserSetting(QWidget* parent=0);
    ~eraserSetting();
signals:
    void sendEraser(eraser en);
    void sendAngle(float angle);

    void sizeChanged();
    void valueChanged();

private slots:
    void reset();
    void resetAngle();
    void angleChanged();

    void setAllEnabled();

    void createEraser();
    void hasChanged();
    void reSize();
    void toRotate();
    void setShapeState(bool s);
    void setPenState(bool s);

private:

    void initConnect();

    bool shapeState;
    bool penState;
    bool localeState;

    QLabel         *eraserText;
    QLabel         *ptbt;
    QDoubleSpinBox *ptb;
    float          ptbv;

    QLabel         *ptt;
    QDoubleSpinBox *pt;
    float          ptv;

    QLabel         *dgrt;
    QDoubleSpinBox *dgr;
    QPushButton    *rotate;
    QPushButton    *resetDgr;
    float          dgrv;

    QLabel         *shapeText;
    shapeSetting   *sps;

    QPushButton    *cancel;
    QPushButton    *apply;

    QGridLayout    *mainLayout;
};

#endif // ERASERSETTING_H
