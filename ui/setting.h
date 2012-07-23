#ifndef SETTING_H
#define SETTING_H

#include "paperSetting.h"
#include "pencilSetting.h"
#include "blenderSetting.h"
#include "eraserSetting.h"

#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>

class setting: public QWidget{

    Q_OBJECT

signals:

private slots:
    void reSize();

public:

    setting(QWidget* parent=0);

    paperSetting   *pp;
    pencilSetting  *pn;
    blenderSetting *bn;
    eraserSetting  *es;

private:
    QVBoxLayout    *mainLayout;
    QTabWidget     *tabs;

};

#endif // SETTING_H
