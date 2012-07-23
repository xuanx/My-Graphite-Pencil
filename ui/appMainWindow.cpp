#include "appMainWindow.h"

appMainWindow::appMainWindow() {

    setWindowTitle("Pencil Grahpite");
    setMinimumSize(800, 600);

    cnvs = new canvas(0,0,this);
    centralArea = new QScrollArea;
    centralArea->setWidget(cnvs);
    centralArea->setAlignment(Qt::AlignCenter);


    setCentralWidget(centralArea);
    settings = new setting;
    settings->show();

    initConnect();

}

void appMainWindow::initConnect() {

    connect(settings->pp, SIGNAL(readyPaper(paper)),    cnvs, SLOT(setPaper(paper)));
    connect(settings->pn, SIGNAL(sendPencil(pencil)),   cnvs, SLOT(setPencil(pencil)));
    connect(settings->bn, SIGNAL(sendBlender(blender)), cnvs, SLOT(setBlender(blender)));
    connect(settings->es, SIGNAL(sendEraser(eraser)),   cnvs, SLOT(setEraser(eraser)));

    connect(settings->pp, SIGNAL(sendActionType(canvas::AT)), cnvs, SLOT(setActionType(canvas::AT)));

}

appMainWindow::~appMainWindow() {

    settings->close();
    delete settings;
    delete cnvs;
    delete centralArea;

}
