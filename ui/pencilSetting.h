#ifndef PENCILSETTING_H
#define PENCILSETTING_H

#include "../core/headers/headers.h"
#include "shapeSetting.h"
#include <QLineEdit>
#include <QColor>
#include <QColorDialog>

class pencilSetting: public QWidget {
    Q_OBJECT
public:
    pencilSetting(QWidget* parent=0);
    ~pencilSetting();
signals:
    void sendPencil(pencil pn);
    void sendAngle(float angle);
    void sendColor(QColor c);

    void sizeChanged();
    void valueChanged();

private slots:
    void reset();
    void resetColor();
    void resetAngle();
    void angleChanged();
    void colorChanged();

    void setAllEnabled();

    void createPencil();
    void hasChanged();
    void reSize();
    void toRotate();
    void selectColor();
    void setShapeState(bool s);
    void setPenState(bool s);

private:

    void initConnect();

    bool shapeState;
    bool penState;
    bool localeState;

    QLabel         *pencilText;
    QLabel         *gpt;
    QDoubleSpinBox *gp;
    float          gpv;

    QLabel         *cpt;
    QDoubleSpinBox *cp;
    float          cpv;

    QLabel         *wpt;
    QDoubleSpinBox *wp;
    float          wpv;

    QLabel         *pdt;
    QDoubleSpinBox *pd;
    float          pdv;

    QLabel         *ptt;
    QDoubleSpinBox *pt;
    float          ptv;

    QLabel         *dgrt;
    QDoubleSpinBox *dgr;
    QPushButton    *rotate;
    QPushButton    *resetDgr;
    float          dgrv;

    QLabel         *colorTxt;
    QLineEdit      *color;
    QPushButton    *resetcolor;
    QPushButton    *update;
    QColorDialog   *selector;
    QColor         colorv;

    QLabel         *shapeText;
    shapeSetting   *sps;

    QPushButton    *cancel;
    QPushButton    *apply;

    QGridLayout    *mainLayout;
};

#endif // PENCILSETTING_H

