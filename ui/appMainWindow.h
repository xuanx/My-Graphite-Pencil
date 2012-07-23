#ifndef APPMAINWINDOW_H
#define APPMAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include "canvas.h"
#include "setting.h"

class appMainWindow: public QMainWindow {

    Q_OBJECT

public:
    appMainWindow();
    ~appMainWindow();

private:
    void initConnect();

    canvas  *cnvs;
    setting *settings;
    QScrollArea *centralArea;

};

#endif // APPMAINWINDOW_H
