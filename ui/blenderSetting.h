#ifndef BLENDERSETTING_H
#define BLENDERSETTING_H

#include "../core/headers/headers.h"
#include "shapeSetting.h"

class blenderSetting: public QWidget {
    Q_OBJECT
public:
    blenderSetting(QWidget* parent=0);
    ~blenderSetting();
signals:
    void sendBlender(blender bn);
    void sendAngle(float angle);

    void sizeChanged();
    void valueChanged();

private slots:
    void reset();
    void resetAngle();
    void angleChanged();

    void setAllEnabled();

    void createBlender();
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

    QLabel         *blenderText;
    QLabel         *ptbt;
    QDoubleSpinBox *ptb;
    float          ptbv;

    QLabel         *btpt;
    QDoubleSpinBox *btp;
    float          btpv;

    QLabel         *cobt;
    QDoubleSpinBox *cob;
    float          cobv;

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

#endif // BLENDERSETTING_H
