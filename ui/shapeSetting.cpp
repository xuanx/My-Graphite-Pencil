#include "shapeSetting.h"

drawShape::drawShape(int w, int h, QWidget *parent): picture(w, h, parent){

    ox = -1;

}

void drawShape::clear() {

    fillWith(Qt::white);
    ox = -1;
    showPicture();
    setEnabled(true);

}

void drawShape::mousePressEvent(QMouseEvent *event) {

    if (event->buttons() & Qt::LeftButton) {
        x2 = event->x();
        y2 = event->y();

        drawRect(x2-1, y2-1, 2, 2);
        if (ox == -1) {
            ox = x1 = x2;
            oy = y1 = y2;
        }
        drawLine(x1, y1, x2, y2);
        showPicture();
        x1 = x2;
        y1 = y2;

        emit sendPoint(x2, y2);
        emit finished(false);

    }
    else if (event->buttons() & Qt::RightButton) {
        drawLine(ox, oy, x2, y2);
        showPicture();
        setEnabled(false);

        emit finished(true);
    }
}



////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


shapeSetting::shapeSetting(QWidget *parent): QWidget(parent) {

    setFixedWidth(200);

    mainLayout = new QGridLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setMargin(0);


    drawArea = new drawShape(200, 200, this);
    drawArea->setEnabled(true);

    mainLayout->addWidget(drawArea, 0, 0, 10, 4, Qt::AlignCenter | Qt::AlignCenter);

    int h = 25;
    pcTxt = new QLabel("C_C:", this);
    pcTxt->setFixedSize(30, h);
    pcTxt->setAlignment(Qt::AlignRight | Qt::AlignCenter);

    pc = new QDoubleSpinBox(this);
    pc->setFixedSize(60, h);
    pc->setDecimals(3);
    pc->setSingleStep(0.001);
    pc->setRange(0,1);
    pc->setValue(0.5);

    scaleTxt = new QLabel("Scale:", this);
    scaleTxt->setFixedSize(55, h);
    scaleTxt->setAlignment(Qt::AlignRight | Qt::AlignCenter);

    scale = new QDoubleSpinBox(this);
    scale->setFixedSize(55, h);
    scale->setDecimals(2);
    scale->setSingleStep(0.01);
    scale->setRange(0,1);
    scale->setValue(0.1);
    scalev = 0.1;

    mainLayout->addWidget(pcTxt, 10, 0, 1, 1, Qt::AlignRight);
    mainLayout->addWidget(pc,    10, 1, 1, 1, Qt::AlignLeft);
    mainLayout->addWidget(scaleTxt, 10, 2, 1, 1, Qt::AlignRight);
    mainLayout->addWidget(scale,    10, 3, 1, 1, Qt::AlignLeft);

    cancel = new QPushButton("Clear", this);
    cancel->setFixedSize(65, h);
    cancel->setEnabled(false);

    /*apply = new QPushButton("Apply", this);
    apply->setFixedSize(60, h);
    apply->setEnabled(false);*/

    reset = new QPushButton("Reset", this);
    reset->setFixedSize(65, h);
    reset->setEnabled(false);

    mainLayout->addWidget(reset,  11, 0, 1, 2, Qt::AlignLeft);
    mainLayout->addWidget(cancel, 11, 2, 1, 2, Qt::AlignRight);
    //mainLayout->addWidget(apply,  11, 3, 1, 2, Qt::AlignRight);

    initConnect();

    adjustSize();

}

void shapeSetting::initConnect() {

    connect(drawArea, SIGNAL(sendPoint(float, float)), this, SLOT(addItem(float, float)));
    connect(drawArea, SIGNAL(finished(bool)), this, SLOT(available(bool)));

    //connect(apply, SIGNAL(clicked()), this, SLOT(createShape()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(clear()));
    connect(reset,  SIGNAL(clicked()), this, SLOT(reSet()));

    connect(pc,    SIGNAL(valueChanged(double)), this, SLOT(valueChanged()));
    connect(scale, SIGNAL(valueChanged(double)), this, SLOT(valueChanged()));

    //connect(this, SIGNAL(valueChanged()), this, SLOT(enableReset()));

}

void shapeSetting::available(bool b) {

    emit finished(b);

    if (b) emit valueChanged(true);

}

void shapeSetting::valueChanged() {

    emit valueChanged(true);
    reset->setEnabled(true);

}

void shapeSetting::addItem(float x, float y, float c) {

    int w1 = 90, w2 = 65, h = 25;

    item *e = new item;
    e->x = x - float(drawArea->width()) / 2;
    e->y = -y + float(drawArea->height()) / 2;

    QString txt = "->(" +
            QString("%1").arg(e->x, 0, 'g', 4) + "," +
            QString("%1").arg(e->y, 0, 'g', 4) + ")=";
    e->axis = new QLabel(txt, this);
    e->axis->setFixedSize(w1, h);
    e->axis->setAlignment(Qt::AlignRight | Qt::AlignCenter);

    e->coe = new QDoubleSpinBox(this);
    e->coe->setAlignment(Qt::AlignLeft | Qt::AlignCenter);
    e->coe->setFixedSize(w2, h);
    e->coe->setDecimals(3);
    e->coe->setSingleStep(0.001);
    e->coe->setRange(0, 1);
    e->coe->setValue(c);

    connect(e->coe, SIGNAL(valueChanged(double)), this, SLOT(valueChanged()));

    points.push_back(e);
    int n = points.size();

    //mainLayout->removeWidget(apply);
    mainLayout->removeWidget(cancel);
    mainLayout->removeWidget(reset);

    mainLayout->addWidget(e->axis, 10+n, 0, 1, 2, Qt::AlignRight);
    mainLayout->addWidget(e->coe,  10+n, 2, 1, 2, Qt::AlignLeft);

    mainLayout->addWidget(reset,  11+n, 0, 1, 2, Qt::AlignLeft);
    mainLayout->addWidget(cancel, 11+n, 2, 1, 2, Qt::AlignRight);
    //mainLayout->addWidget(apply,  11+n, 3, 1, 2, Qt::AlignRight);

    cancel->setEnabled(true);
    reset->setEnabled(true);

    adjustSize();
    emit sizeChanged();
}

void shapeSetting::clear() {

    drawArea->clear();
    int n = points.size();
    for (int i = 0; i < n; ++i) {
        mainLayout->removeWidget(points[i]->axis);
        mainLayout->removeWidget(points[i]->coe);
        delete points[i]->axis;
        delete points[i]->coe;
        delete points[i];
    }
    adjustSize();
    points.clear();

    pc->setValue(0.5);
    scale->setValue(0.1);

    if (sp.getPolygen().size() == 0)
        reset->setEnabled(false);
    else
        reset->setEnabled(true);
    cancel->setEnabled(false);
    drawArea->setEnabled(true);
    //apply->setEnabled(false);

    emit sizeChanged();
    emit finished(false);
    emit valueChanged(true);

}

void shapeSetting::reSet() {

    clear();

    int n = sp.getPolygen().size();
    if (n > 0) {

        pc->setValue(sp[shape::C_C]);
        scale->setValue(scalev);

        float ox=float(drawArea->width()) / 2;
        float oy=float(drawArea->height()) / 2;
        float x0, y0, x1, y1, x2, y2, c;

        x0 = x1 = sp.getPolygen()[0][point::X] / scalev;
        y0 = y1 = sp.getPolygen()[0][point::Y] / scalev;

        c  = sp.getPolygen()[0][point::P_C];
        addItem(int(x1+ox), int(oy-y1), c);

        for(int i = 1; i < n; ++i) {
            x2 = sp.getPolygen()[i][point::X] / scalev;
            y2 = sp.getPolygen()[i][point::Y] / scalev;
            c  = sp.getPolygen()[i][point::P_C];

            addItem(int(x2+ox), int(oy-y2), c);

            drawArea->drawLine(int(x1+ox), int(oy-y1), int(x2+ox), int(oy-y2));

            x1 = x2;
            y1 = y2;
        }
        drawArea->drawLine(int(x0+ox), int(oy-y0), int(x1+ox), int(oy-y1));
        drawArea->setEnabled(false);

        adjustSize();
        emit sizeChanged();
        emit finished(true);
    }
    emit valueChanged(false);
    reset->setEnabled(false);
}

shape& shapeSetting::createShape() {

    int size = points.size();

    float *p_c = new float[size];
    V2D   *p_s = new V2D[size];

    scalev = scale->value();
    for (int i = 0; i < size; ++i) {
        p_c[i] = points[i]->coe->value();
        p_s[i] = V2D(points[i]->x * scalev, points[i]->y * scalev);
    }

    sp[shape::C_C] = pc->value();
    sp.setShape(p_c, polygen(p_s, p_s+size));


    //apply->setEnabled(false);
    reset->setEnabled(false);
    emit valueChanged(false);
    emit finished(true);
    //emit sendShape(sp);

    delete p_c;
    delete p_s;

    return sp;
}

shapeSetting::~shapeSetting() {

    clear();
    delete drawArea;

    delete pc;
    delete pcTxt;
    delete cancel;
    //delete apply;

    delete mainLayout;

}
