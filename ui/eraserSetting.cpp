#include "eraserSetting.h"

eraserSetting::eraserSetting(QWidget* parent): QWidget(parent) {

    int w = 220, h = 25, w1 = 30, w2 = 65, d = 3;
    float s = 0.001;
    setFixedWidth(w);
    shapeState = false;
    penState = false;
    localeState = false;

    mainLayout = new QGridLayout(this);
    mainLayout->setColumnMinimumWidth(2, 5);
    mainLayout->setRowMinimumHeight(4, 5);
    mainLayout->setRowMinimumHeight(6, 5);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    shapeText = new QLabel("Eraser Shape:", this);
    shapeText->setFixedSize(200, h);
    shapeText->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    sps = new shapeSetting(this);
    mainLayout->addWidget(shapeText, 0, 0, 1, 5, Qt::AlignLeft | Qt::AlignCenter);
    mainLayout->addWidget(sps, 1, 0, 1, 5, Qt::AlignCenter | Qt::AlignCenter);

    eraserText = new QLabel("Eraser Infomation:", this);
    eraserText->setFixedSize(200, h);
    eraserText->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    mainLayout->addWidget(eraserText, 2, 0, 1, 5, Qt::AlignLeft | Qt::AlignCenter);

    ptbt = new QLabel("PTB:", this);
    ptbt->setFixedSize(w1, h);
    ptbt->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    ptb = new QDoubleSpinBox(this);
    ptb->setFixedSize(w2, h);
    ptb->setRange(0, 1);
    ptb->setDecimals(d);
    ptb->setSingleStep(s);
    ptb->setValue(0.5);
    ptbv = 0.5;

    mainLayout->addWidget(ptbt, 3, 0, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(ptb , 3, 1, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);

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

    mainLayout->addWidget(ptt, 3, 3, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(pt , 3, 4, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);

    cancel = new QPushButton("Cancel", this);
    cancel->setFixedSize(w2, h);
    cancel->setEnabled(false);
    apply = new QPushButton("Apply", this);
    apply->setFixedSize(w2, h);
    apply->setEnabled(false);

    mainLayout->addWidget(cancel, 5, 0, 1, 2, Qt::AlignLeft  | Qt::AlignCenter);
    mainLayout->addWidget(apply,  5, 3, 1, 2, Qt::AlignRight | Qt::AlignCenter);

    dgrt = new QLabel("DGR:", this);
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

    mainLayout->addWidget(dgrt,     7, 0, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(dgr ,     7, 1, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);
    mainLayout->addWidget(resetDgr, 7, 3, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);
    mainLayout->addWidget(rotate,   7, 4, 1, 1, Qt::AlignRight | Qt::AlignCenter);

    mainLayout->setRowMinimumHeight(8, 0);
    mainLayout->setRowStretch(8, INT_MAX);

    setLayout(mainLayout);
    adjustSize();

    initConnect();

}

eraserSetting::~eraserSetting() {

    delete ptbt;
    delete ptb;

    delete ptt;
    delete pt;

    delete dgrt;
    delete dgr;
    delete rotate;

    delete sps;

    delete cancel;
    delete apply;
    delete shapeText;
    delete eraserText;

    delete mainLayout;
}


void eraserSetting::initConnect() {

    connect(cancel, SIGNAL(clicked()), this, SLOT(reset()));
    connect(apply,  SIGNAL(clicked()), this, SLOT(createEraser())); // create and then send paper

    connect(sps, SIGNAL(finished(bool)),   this, SLOT(setShapeState(bool)));
    connect(sps, SIGNAL(valueChanged(bool)), this, SLOT(setPenState(bool)));
    connect(sps, SIGNAL(sizeChanged()),  this, SLOT(reSize()));

    connect(ptb, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(pt, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));

    connect(dgr,      SIGNAL(valueChanged(double)), this, SLOT(angleChanged()));
    connect(rotate,   SIGNAL(clicked()), this, SLOT(toRotate()));
    connect(resetDgr, SIGNAL(clicked()), this, SLOT(resetAngle()));

}

//////////////////////////////////////////////////////////////
////////////     SLOTS        ////////////////////////////////
//////////////////////////////////////////////////////////////

void eraserSetting::reset() {

    //sps->reSet();
    ptb->setValue(double(ptbv));
    pt->setValue(double(ptv));

    localeState = false;

    setAllEnabled();

}

void eraserSetting::createEraser() {

    eraser en;
    ptbv = float(ptb->value());
    ptv = float(pt->value());

    en(eraser::PLR_PTB, ptbv);
    en(eraser::P_T, ptv);

    shape sp = sps->createShape();
    en.sharpen(sp);

    penState = false;
    shapeState = true;
    localeState = false;

    setAllEnabled();

    rotate->setEnabled(true);
    resetDgr->setEnabled(true);

    emit sendEraser(en);

}

void eraserSetting::setShapeState(bool s) {

    shapeState = s;

    setAllEnabled();
    //hasChanged();

}

void eraserSetting::setPenState(bool s) {

    penState = s;

    setAllEnabled();
    //hasChanged();

}

void eraserSetting::hasChanged() {

    localeState = true;

    setAllEnabled();

}

void eraserSetting::setAllEnabled() {

    apply->setEnabled(shapeState && (penState || localeState));
    cancel->setEnabled(localeState);

}

void eraserSetting::reSize() {

    adjustSize();
    emit sizeChanged();

}


void eraserSetting::angleChanged() {

    resetDgr->setEnabled(true);
    rotate->setEnabled(true);

}

void eraserSetting::toRotate() {

    dgrv = float(dgr->value());
    emit sendAngle(dgrv);
    resetDgr->setEnabled(false);
    rotate->setEnabled(false);

}

void eraserSetting::resetAngle() {

    dgr->setValue(double(dgrv));
    resetDgr->setEnabled(false);
    rotate->setEnabled(false);

}
