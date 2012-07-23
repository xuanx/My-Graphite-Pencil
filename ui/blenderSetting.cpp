#include "blenderSetting.h"

blenderSetting::blenderSetting(QWidget* parent): QWidget(parent) {

    int w = 220, h = 25, w1 = 30, w2 = 65, d = 3;
    float s = 0.001;
    setFixedWidth(w);
    shapeState = false;
    penState = false;
    localeState = false;

    mainLayout = new QGridLayout(this);
    mainLayout->setColumnMinimumWidth(2, 5);
    mainLayout->setRowMinimumHeight(5, 5);
    mainLayout->setRowMinimumHeight(7, 5);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    shapeText = new QLabel("Blender Shape:", this);
    shapeText->setFixedSize(200, h);
    shapeText->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    sps = new shapeSetting(this);
    mainLayout->addWidget(shapeText, 0, 0, 1, 5, Qt::AlignLeft | Qt::AlignCenter);
    mainLayout->addWidget(sps, 1, 0, 1, 5, Qt::AlignCenter | Qt::AlignCenter);

    blenderText = new QLabel("Blender Infomation:", this);
    blenderText->setFixedSize(200, h);
    blenderText->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    mainLayout->addWidget(blenderText, 2, 0, 1, 5, Qt::AlignLeft | Qt::AlignCenter);

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

    btpt = new QLabel("BTP:", this);
    btpt->setFixedSize(w1, h);
    btpt->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    btp = new QDoubleSpinBox(this);
    btp->setFixedSize(w2, h);
    btp->setRange(0, 1);
    btp->setDecimals(d);
    btp->setSingleStep(s);
    btp->setValue(0.5);
    btpv = 0.5;

    mainLayout->addWidget(btpt, 4, 0, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(btp , 4, 1, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);

    cobt = new QLabel("COB:", this);
    cobt->setFixedSize(w1, h);
    cobt->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    cob = new QDoubleSpinBox(this);
    cob->setFixedSize(w2, h);
    cob->setRange(0, 1);
    cob->setDecimals(d);
    cob->setSingleStep(s);
    cob->setValue(0.5);
    cobv = 0.5;

    mainLayout->addWidget(cobt, 3, 3, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(cob , 3, 4, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);

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

    mainLayout->addWidget(cancel, 6, 0, 1, 2, Qt::AlignLeft  | Qt::AlignCenter);
    mainLayout->addWidget(apply,  6, 3, 1, 2, Qt::AlignRight | Qt::AlignCenter);

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

    mainLayout->addWidget(dgrt,     8, 0, 1, 1, Qt::AlignRight | Qt::AlignCenter);
    mainLayout->addWidget(dgr ,     8, 1, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);
    mainLayout->addWidget(resetDgr, 8, 3, 1, 1, Qt::AlignLeft  | Qt::AlignCenter);
    mainLayout->addWidget(rotate,   8, 4, 1, 1, Qt::AlignRight | Qt::AlignCenter);

    mainLayout->setRowMinimumHeight(9, 0);
    mainLayout->setRowStretch(9, INT_MAX);

    setLayout(mainLayout);
    adjustSize();

    initConnect();

}

blenderSetting::~blenderSetting() {

    delete ptbt;
    delete ptb;

    delete btpt;
    delete btp;

    delete cobt;
    delete cob;

    delete ptt;
    delete pt;

    delete dgrt;
    delete dgr;
    delete rotate;

    delete sps;

    delete cancel;
    delete apply;
    delete shapeText;
    delete blenderText;

    delete mainLayout;
}


void blenderSetting::initConnect() {

    connect(cancel, SIGNAL(clicked()), this, SLOT(reset()));
    connect(apply,  SIGNAL(clicked()), this, SLOT(createBlender())); // create and then send paper

    connect(sps, SIGNAL(finished(bool)),   this, SLOT(setShapeState(bool)));
    connect(sps, SIGNAL(valueChanged(bool)), this, SLOT(setPenState(bool)));
    connect(sps, SIGNAL(sizeChanged()),  this, SLOT(reSize()));

    connect(ptb, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(btp, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(cob, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(pt, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));

    connect(dgr,      SIGNAL(valueChanged(double)), this, SLOT(angleChanged()));
    connect(rotate,   SIGNAL(clicked()), this, SLOT(toRotate()));
    connect(resetDgr, SIGNAL(clicked()), this, SLOT(resetAngle()));

}

//////////////////////////////////////////////////////////////
////////////     SLOTS        ////////////////////////////////
//////////////////////////////////////////////////////////////

void blenderSetting::reset() {

    //sps->reSet();
    ptb->setValue(double(ptbv));
    cob->setValue(double(cobv));
    btp->setValue(double(btpv));
    pt->setValue(double(ptv));

    localeState = false;

    setAllEnabled();

}

void blenderSetting::createBlender() {

    blender bn;
    ptbv = float(ptb->value());
    cobv = float(cob->value());
    btpv = float(btp->value());
    ptv = float(pt->value());

    bn(blender::PLR_PTB, ptbv);
    bn(blender::PLR_BTP, cobv);
    bn(blender::COB, btpv);
    bn(blender::P_T, ptv);

    shape sp = sps->createShape();
    bn.sharpen(sp);

    penState = false;
    shapeState = true;
    localeState = false;

    setAllEnabled();

    rotate->setEnabled(true);
    resetDgr->setEnabled(true);

    emit sendBlender(bn);

}

void blenderSetting::setShapeState(bool s) {

    shapeState = s;

    setAllEnabled();
    //hasChanged();

}

void blenderSetting::setPenState(bool s) {

    penState = s;

    setAllEnabled();
    //hasChanged();

}

void blenderSetting::hasChanged() {

    localeState = true;

    setAllEnabled();

}

void blenderSetting::setAllEnabled() {

    apply->setEnabled(shapeState && (penState || localeState));
    cancel->setEnabled(localeState);

}

void blenderSetting::reSize() {

    adjustSize();
    emit sizeChanged();

}


void blenderSetting::angleChanged() {

    resetDgr->setEnabled(true);
    rotate->setEnabled(true);

}

void blenderSetting::toRotate() {

    dgrv = float(dgr->value());
    emit sendAngle(dgrv);
    resetDgr->setEnabled(false);
    rotate->setEnabled(false);

}

void blenderSetting::resetAngle() {

    dgr->setValue(double(dgrv));
    resetDgr->setEnabled(false);
    rotate->setEnabled(false);

}

