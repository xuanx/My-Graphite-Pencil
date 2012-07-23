#include "setting.h"

setting::setting(QWidget *parent): QWidget(parent) {

    setWindowTitle("Settings");

    pp = new paperSetting(this);
    pn = new pencilSetting(this);
    bn = new blenderSetting(this);
    es = new eraserSetting(this);

    tabs = new QTabWidget(this);
    mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);

    tabs->addTab(pp, "Paper");
    tabs->addTab(pn, "Pencil");
    tabs->addTab(bn, "Blender");
    tabs->addTab(es, "Eraser");

    mainLayout->addWidget(tabs);
    setLayout(mainLayout);
    setFixedWidth(230);

    adjustSize();

    connect(pn, SIGNAL(sizeChanged()), this, SLOT(reSize()));
    connect(bn, SIGNAL(sizeChanged()), this, SLOT(reSize()));
    connect(es, SIGNAL(sizeChanged()), this, SLOT(reSize()));
    connect(tabs, SIGNAL(currentChanged(int)), this, SLOT(reSize()));

}

void setting::reSize() {


    tabs->currentWidget()->adjustSize();
    tabs->adjustSize();
    adjustSize();

}
