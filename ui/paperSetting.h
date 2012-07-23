#ifndef PAPERSETTING_H
#define PAPERSETTING_H

#include "../core/headers/headers.h"
#include "canvas.h"
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QString>

class paperSetting: public QWidget{
    Q_OBJECT

public:
    paperSetting(QWidget* parent=0);
    ~paperSetting();

signals:
    void readyPaper(paper pp);
    void requireInfo();

    void valueChanged(bool);
    void sendActionType(canvas::AT);

private slots:
    void hasChanged();

    void setURL();
    void delURL();

    void createPaper();
    void reset(paper& pp);

    void setDrawAction();
    void setEraseAction();
    void setNoneAction();

private:

    void initPaper(paper& pp);
    void initConnect();

    QPushButton *drawAction;
    QPushButton *eraseAction;
    QPushButton *noneAction;


    QString      oldFname;
    QString      newFname;

    QLabel*      infomation;

    //width
    QLabel*      widthLabel;
    QSpinBox*    width;
    QLabel*      wpx;

    //height
    QLabel*      heightLabel;
    QSpinBox*    height;
    QLabel*      hpx;

    //P_W
    QLabel*         pwLabel;
    QDoubleSpinBox* pw;
    QLabel*         pwRange;

    //P_M
    //width
    QLabel*         pmLabel;
    QDoubleSpinBox* pm;
    QLabel*         pmRange;

    //F_S
    //width
    QLabel*      fsLabel;
    QSpinBox*    fs;
    QLabel*      fsRange;

    //F_V
    QLabel*      fvLabel;
    QSpinBox*    fv;
    QLabel*      fvRange;

    //texture
    QLabel*      texture;

    QPushButton* fromPaper;
    QLineEdit*   url;
    QPushButton* random;
    QPushButton* apply;
    QPushButton* cancel;

    QGridLayout* mainLayout;
};

#endif // PAPERSETTING_H
