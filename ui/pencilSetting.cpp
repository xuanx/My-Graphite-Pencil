#include "pencilSetting.h"

pencilSetting::pencilSetting(QWidget* parent): QWidget(parent) {

    int w = 220, h = 25, w1 = 30, w2 = 65, d = 3;
    float s = 0.001;
    setFixedWidth(w);
    shapeState = false;
    penState = false;
    localeState = false;

    mainLayout = new QGridLayout(this);
    mainLayout->setColumnMinimumWidth(2, 5);
    mainLayout->setRowMinimumHeight(6, 5);
    mainLayout->setRowMinimumHeight(8, 5);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    shapeText = new QLabel("Pencil Shape:", this);
    shapeText->setFixedSize(200, h);
    shapeText->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    sps = new shapeSetting(this);
    mainLayout->addWidget(shapeText, 0, 0, 1, 5, Qt::AlignLeft | Qt::AlignCenter);
    mainLayout->addWidget(sps, 1, 0, 1, 5, Qt::AlignCenter | Qt::AlignCenter);

    pencilText = new QLabel("Pencil Infomation:", this);
    pencilText->setFixedSize(200, h);
    pencilText->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    mainLayout->addWidget(pencilText, 2, 0, 1, 5, Qt::AlignLeft | Qt::AlignCenter);

    gpt = new QLabel("G_P:", this);
    gpt->setFixedSize(w1, h);
    gpt->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    gp = new QDoubleSpinBox(this);
    gp->setFixedSize(w2, h);
    gp->setRange(0, 1);
    gp->setDecimals(d);
    gp->setSingleStep(s);
    gp->setValue(0.5);
    gpv = 0.5;

    mainLayout->addWidget(gpt, 3, 0, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(gp , 3, 1, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);

    cpt = new QLabel("C_P:", this);
    cpt->setFixedSize(w1, h);
    cpt->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    cp = new QDoubleSpinBox(this);
    cp->setFixedSize(w2, h);
    cp->setRange(0, 1);
    cp->setDecimals(d);
    cp->setSingleStep(s);
    cp->setValue(0.5);
    cpv = 0.5;

    mainLayout->addWidget(cpt, 4, 0, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(cp , 4, 1, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);

    wpt = new QLabel("W_P:", this);
    wpt->setFixedSize(w1, h);
    wpt->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    wp = new QDoubleSpinBox(this);
    wp->setFixedSize(w2, h);
    wp->setRange(0, 1);
    wp->setDecimals(d);
    wp->setSingleStep(s);
    wp->setValue(0.5);
    wpv = 0.5;

    mainLayout->addWidget(wpt, 5, 0, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(wp , 5, 1, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);

    pdt = new QLabel("P_D:", this);
    pdt->setFixedSize(w1, h);
    pdt->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    pd = new QDoubleSpinBox(this);
    pd->setFixedSize(w2, h);
    pd->setRange(0, 1);
    pd->setDecimals(d);
    pd->setSingleStep(s);
    pd->setValue(0.5);
    pdv = 0.5;

    mainLayout->addWidget(pdt, 3, 3, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(pd , 3, 4, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);

    ptt = new QLabel("P_T:", this);
    ptt->setFixedSize(w1, h);
    ptt->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    pt = new QDoubleSpinBox(this);
    pt->setFixedSize(w2, h);
    pt->setRange(0, 1);
    pt->setDecimals(d);
    pt->setSingleStep(s);
    pt->setValue(0.5);
    ptv = 0.5;

    mainLayout->addWidget(ptt, 4, 3, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(pt , 4, 4, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);

    cancel = new QPushButton("Cancel", this);
    cancel->setFixedSize(w2, h);
    cancel->setEnabled(false);
    apply = new QPushButton("Apply", this);
    apply->setFixedSize(w2, h);
    apply->setEnabled(false);

    mainLayout->addWidget(cancel, 7, 0, 1, 2, Qt::AlignLeft  | Qt::AlignCenter);
    mainLayout->addWidget(apply,  7, 3, 1, 2, Qt::AlignRight | Qt::AlignCenter);

    dgrt = new QLabel("dgr:", this);
    dgrt->setFixedSize(50, h);
    dgrt->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    dgr = new QDoubleSpinBox(this);
    dgr->setFixedSize(60, h);
    dgr->setRange(-180, 180);
    dgr->setDecimals(2);
    dgr->setSingleStep(0.01);
    dgr->setValue(0);
    dgrv = 0.5;
    resetDgr = new QPushButton("Reset", this);
    resetDgr->setFixedSize(40, h);
    resetDgr->setEnabled(false);
    rotate = new QPushButton("Rotate", this);
    rotate->setFixedSize(50, h);
    rotate->setEnabled(false);

    mainLayout->addWidget(dgrt,     9, 0, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(dgr ,     9, 1, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);
    mainLayout->addWidget(resetDgr, 9, 3, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);
    mainLayout->addWidget(rotate,   9, 4, 1, 1, Qt::AlignRight | Qt::AlignCenter);

    selector = new QColorDialog(Qt::black, this);
    colorTxt = new QLabel("Color:", this);
    colorTxt->setFixedSize(45, h);
    colorTxt->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    color = new QLineEdit("#000000", this);
    color->setAlignment(Qt::AlignLeft | Qt::AlignCenter);
    color->setFixedSize(60, h);
    colorv = Qt::black;
    resetcolor = new QPushButton("Reset", this);
    resetcolor->setFixedSize(40, h);
    resetcolor->setEnabled(false);
    update = new QPushButton("Update", this);
    update->setFixedSize(50, h);
    update->setEnabled(false);

    mainLayout->addWidget(colorTxt,   10, 0, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(color   ,   10, 1, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);
    mainLayout->addWidget(resetcolor, 10, 3, 1, 1, Qt::AlignLeft | Qt::AlignCenter);
    mainLayout->addWidget(update  ,   10, 4, 1, 1, Qt::AlignRight | Qt::AlignCenter);

    mainLayout->setRowMinimumHeight(9, 0);
    mainLayout->setRowStretch(11, INT_MAX);

    setLayout(mainLayout);
    adjustSize();

    initConnect();

}

pencilSetting::~pencilSetting() {

    delete gpt;
    delete gp;

    delete cpt;
    delete cp;

    delete wpt;
    delete wp;

    delete pdt;
    delete pd;

    delete ptt;
    delete pt;

    delete dgrt;
    delete dgr;
    delete rotate;

    delete colorTxt;
    delete color;
    delete resetcolor;
    delete update;
    delete selector;

    delete sps;

    delete cancel;
    delete apply;
    delete shapeText;
    delete pencilText;

    delete mainLayout;
}


void pencilSetting::initConnect() {

    connect(cancel, SIGNAL(clicked()), this, SLOT(reset()));
    connect(apply,  SIGNAL(clicked()), this, SLOT(createPencil())); // create and then send paper

    connect(sps, SIGNAL(finished(bool)),   this, SLOT(setShapeState(bool)));
    connect(sps, SIGNAL(valueChanged(bool)), this, SLOT(setPenState(bool)));
    connect(sps, SIGNAL(sizeChanged()),  this, SLOT(reSize()));

    connect(gp, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(cp, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(wp, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(pt, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(pd, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));

    connect(dgr,      SIGNAL(valueChanged(double)), this, SLOT(angleChanged()));
    connect(rotate,   SIGNAL(clicked()), this, SLOT(toRotate()));
    connect(resetDgr, SIGNAL(clicked()), this, SLOT(resetAngle()));

    connect(color,      SIGNAL(textChanged(QString)), this, SLOT(colorChanged()));
    connect(resetcolor, SIGNAL(clicked()), this, SLOT(resetColor()));
    connect(update,     SIGNAL(clicked()), this, SLOT(selectColor()));

}

//////////////////////////////////////////////////////////////
////////////     SLOTS        ////////////////////////////////
//////////////////////////////////////////////////////////////

void pencilSetting::reset() {

    //sps->reSet();
    gp->setValue(double(gpv));
    wp->setValue(double(wpv));
    cp->setValue(double(cpv));
    pt->setValue(double(ptv));
    pd->setValue(double(pdv));

    localeState = false;

    setAllEnabled();

}

void pencilSetting::createPencil() {

    pencil pn;
    gpv = float(gp->value());
    wpv = float(wp->value());
    cpv = float(cp->value());
    ptv = float(pt->value());
    pdv = float(pd->value());

    pn(pencil::G_P, gpv);
    pn(pencil::W_P, wpv);
    pn(pencil::C_P, cpv);
    pn(pencil::P_T, ptv);
    pn(pencil::P_D, pdv);

    shape sp = sps->createShape();
    pn.sharpen(sp);

    penState = false;
    shapeState = true;
    localeState = false;

    setAllEnabled();

    rotate->setEnabled(true);
    resetDgr->setEnabled(true);
    update->setEnabled(true);
    resetcolor->setEnabled(true);

    emit sendPencil(pn);

}

void pencilSetting::setShapeState(bool s) {

    shapeState = s;

    setAllEnabled();
    //hasChanged();

}

void pencilSetting::setPenState(bool s) {

    penState = s;

    setAllEnabled();
    //hasChanged();

}

void pencilSetting::hasChanged() {

    localeState = true;

    setAllEnabled();

}

void pencilSetting::setAllEnabled() {

    apply->setEnabled(shapeState && (penState || localeState));
    cancel->setEnabled(localeState);

}

void pencilSetting::reSize() {

    adjustSize();
    emit sizeChanged();

}


void pencilSetting::angleChanged() {

    resetDgr->setEnabled(true);
    rotate->setEnabled(true);

}

void pencilSetting::toRotate() {

    dgrv = float(dgr->value());
    emit sendAngle(dgrv);
    resetDgr->setEnabled(false);
    rotate->setEnabled(false);

}

void pencilSetting::resetAngle() {

    dgr->setValue(double(dgrv));
    resetDgr->setEnabled(false);
    rotate->setEnabled(false);

}

void pencilSetting::colorChanged() {

    resetcolor->setEnabled(true);
    update->setEnabled(true);

}

void pencilSetting::resetColor() {

    color->setText(colorv.name());
    resetcolor->setEnabled(false);
    update->setEnabled(false);

}


void pencilSetting::selectColor() {

    selector->raise();
    selector->setCurrentColor(QColor(color->text()));
    if (selector->exec()) {
        colorv = selector->currentColor();
        color->setText(colorv.name());
        emit sendColor(colorv);
        resetcolor->setEnabled(false);
        update->setEnabled(false);
    }
}


