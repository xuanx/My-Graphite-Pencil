#include "paperSetting.h"
#include <cstdlib>
#include <ctime>
#include <QImage>
#include <QFileDialog>

paperSetting::paperSetting(QWidget* parent): QWidget(parent) {

    oldFname = newFname = "";

    int w1 = 50, w2 = 68, w3 = 82, w = 200, h = 23;
    mainLayout = new QGridLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setRowMinimumHeight(10, 5);
    setLayout(mainLayout);

    infomation = new QLabel("Infomation:", this);
    infomation->setFixedSize(w, h);
    infomation->setAlignment(Qt::AlignLeft | Qt::AlignBottom);

    mainLayout->addWidget(infomation, 0, 0, 1, 3, Qt::AlignLeft | Qt::AlignBottom);


    //width
    widthLabel = new QLabel("Width:", this);
    widthLabel->setFixedSize(w1, h);
    widthLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    width = new QSpinBox(this);
    width->setFixedSize(w2, h);
    width->setRange(100, 5000);
    width->setValue(500);

    wpx = new QLabel("px(100~5000)", this);
    wpx->setFixedSize(w3, h);
    wpx->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    mainLayout->addWidget(widthLabel, 1, 0, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
    mainLayout->addWidget(width     , 1, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    mainLayout->addWidget(wpx       , 1, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    //height
    heightLabel = new QLabel("Height:", this);
    heightLabel->setFixedSize(w1, h);
    heightLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    height = new QSpinBox(this);
    height->setFixedSize(w2, h);
    height->setRange(100, 5000);
    height->setValue(500);

    hpx = new QLabel("px(100~5000)", this);
    hpx->setFixedSize(w3, h);
    hpx->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    mainLayout->addWidget(heightLabel, 2, 0, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
    mainLayout->addWidget(height     , 2, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    mainLayout->addWidget(hpx        , 2, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    //P_W
    pwLabel = new QLabel("P_W:", this);
    pwLabel->setFixedSize(w1, h);
    pwLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    pw = new QDoubleSpinBox(this);
    pw->setFixedSize(w2, h);
    pw->setDecimals(4);
    pw->setSingleStep(0.0001);
    pw->setRange(0, 1);
    pw->setValue(0.5);

    pwRange = new QLabel("(0~1)", this);
    pwRange->setFixedSize(w3, h);
    pwRange->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    mainLayout->addWidget(pwLabel , 3, 0, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
    mainLayout->addWidget(pw      , 3, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    mainLayout->addWidget(pwRange , 3, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    //P_M
    pmLabel = new QLabel("P_M:", this);
    pmLabel->setFixedSize(w1, h);
    pmLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    pm = new QDoubleSpinBox(this);
    pm->setFixedSize(w2, h);
    pm->setDecimals(4);
    pm->setSingleStep(0.0001);
    pm->setRange(0, 1);
    pm->setValue(0.5);

    pmRange = new QLabel("(0~1)", this);
    pmRange->setFixedSize(w3, h);
    pmRange->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    mainLayout->addWidget(pmLabel , 4, 0, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
    mainLayout->addWidget(pm      , 4, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    mainLayout->addWidget(pmRange , 4, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    //F_S
    fsLabel = new QLabel("F_S:", this);
    fsLabel->setFixedSize(w1, h);
    fsLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    fs = new QSpinBox(this);
    fs->setFixedSize(w2, h);
    fs->setRange(400, 600);
    fs->setValue(500);

    fsRange = new QLabel("(400~600)", this);
    fsRange->setFixedSize(w3, h);
    fsRange->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    mainLayout->addWidget(fsLabel , 5, 0, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
    mainLayout->addWidget(fs      , 5, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    mainLayout->addWidget(fsRange , 5, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    //F_V
    fvLabel = new QLabel("F_V:", this);
    fvLabel->setFixedSize(w1, h);
    fvLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    fv = new QSpinBox(this);
    fv->setFixedSize(w2, h);
    fv->setRange(1000, 3000);
    fv->setValue(2000);

    fvRange = new QLabel("(1000~3000)", this);
    fvRange->setFixedSize(w3, h);
    fvRange->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    mainLayout->addWidget(fvLabel , 6, 0, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
    mainLayout->addWidget(fv      , 6, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    mainLayout->addWidget(fvRange , 6, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    //texture
    texture = new QLabel("Texture:", this);
    texture->setFixedSize(w, h);
    texture->setAlignment(Qt::AlignLeft | Qt::AlignBottom);

    mainLayout->addWidget(texture, 7, 0, 1, 4, Qt::AlignLeft | Qt::AlignBottom);


    fromPaper = new QPushButton("From", this);
    fromPaper->setFixedSize(w1, h);

    url = new QLineEdit();
    url->setFixedSize(w-w1, h);
    url->setText("");
    url->setEnabled(false);

    mainLayout->addWidget(fromPaper, 8, 0, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
    mainLayout->addWidget(url      , 8, 1, 1, 2, Qt::AlignLeft | Qt::AlignVCenter);



    random = new QPushButton("Random", this);
    random->setFixedSize(w1, h);

    apply = new QPushButton("Apply", this);
    apply->setFixedSize(w1, h);
    apply->setEnabled(true);
    cancel = new QPushButton("Cancel", this);
    cancel->setFixedSize(w1, h);
    cancel->setEnabled(false);

    mainLayout->addWidget(random, 9, 0, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
    mainLayout->addWidget(cancel, 9, 1, 1, 2, Qt::AlignCenter |Qt::AlignVCenter);
    mainLayout->addWidget(apply , 9, 2, 1, 1, Qt::AlignRight | Qt::AlignVCenter);

    drawAction = new QPushButton("Draw", this);
    drawAction->setFixedSize(50, h);
    drawAction->setEnabled(true);

    eraseAction = new QPushButton("Erase", this);
    eraseAction->setFixedSize(50, h);
    eraseAction->setEnabled(true);

    noneAction = new QPushButton("None", this);
    noneAction->setFixedSize(50, h);
    noneAction->setEnabled(false);

    mainLayout->addWidget(noneAction,  11, 0, 1, 1, Qt::AlignLeft  | Qt::AlignVCenter);
    mainLayout->addWidget(eraseAction, 11, 1, 1, 2, Qt::AlignCenter | Qt::AlignVCenter);
    mainLayout->addWidget(drawAction,  11, 2, 1, 1, Qt::AlignRight  | Qt::AlignVCenter);

    setFixedSize(sizeHint());
    initConnect();
}

void paperSetting::initConnect() {

    connect(fromPaper, SIGNAL(clicked()), this, SLOT(setURL()));
    connect(random,    SIGNAL(clicked()), this, SLOT(delURL()));
    connect(cancel,    SIGNAL(clicked()), this, SIGNAL(requireInfo()));
    connect(apply,     SIGNAL(clicked()), this, SLOT(createPaper()));

    connect(width , SIGNAL(valueChanged(int)),    this, SLOT(hasChanged()));
    connect(height, SIGNAL(valueChanged(int)),    this, SLOT(hasChanged()));
    connect(pw,     SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(pm,     SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(fs,     SIGNAL(valueChanged(int)),    this, SLOT(hasChanged()));
    connect(fv,     SIGNAL(valueChanged(int)),    this, SLOT(hasChanged()));
    connect(url,    SIGNAL(textChanged(QString)), this, SLOT(hasChanged()));

    connect(this,   SIGNAL(valueChanged(bool)),  apply, SLOT(setEnabled(bool)));
    connect(this,   SIGNAL(valueChanged(bool)), cancel, SLOT(setEnabled(bool)));

    connect(drawAction,  SIGNAL(clicked()), this, SLOT(setDrawAction()));
    connect(eraseAction, SIGNAL(clicked()), this, SLOT(setEraseAction()));
    connect(noneAction,  SIGNAL(clicked()), this, SLOT(setNoneAction()));

}

void paperSetting::setDrawAction() {

    emit sendActionType(canvas::DRAW);
    drawAction->setEnabled(false);
    eraseAction->setEnabled(true);
    noneAction->setEnabled(true);

}

void paperSetting::setEraseAction() {

    emit sendActionType(canvas::ERASE);
    drawAction->setEnabled(true);
    eraseAction->setEnabled(false);
    noneAction->setEnabled(true);

}

void paperSetting::setNoneAction() {

    emit sendActionType(canvas::NONE);
    drawAction->setEnabled(true);
    eraseAction->setEnabled(true);
    noneAction->setEnabled(false);

}

paperSetting::~paperSetting(){
    delete infomation;

    //width
    delete widthLabel;
    delete width;
    delete wpx;

    //height
    delete heightLabel;
    delete height;
    delete hpx;

    //P_W
    delete pwLabel;
    delete pw;
    delete pwRange;

    //P_M
    delete pmLabel;
    delete pm;
    delete pmRange;

    //F_S
    delete fsLabel;
    delete fs;
    delete fsRange;

    //F_V
    delete fvLabel;
    delete fv;
    delete fvRange;

    //texture
    delete texture;

    delete fromPaper;
    delete url;
    delete random;
    delete apply;
    delete cancel;

    delete drawAction;
    delete eraseAction;
    delete noneAction;

    delete mainLayout;
}

void paperSetting::hasChanged() {

    emit valueChanged(true);

}

void paperSetting::initPaper(paper& pp) {

    pp(paper::W, float(width->value()));
    pp(paper::H, float(height->value()));
    pp(paper::P_W, float(pw->value()));
    pp(paper::P_M, float(pm->value()));
    pp(paper::F_S, float(fs->value()));
    pp(paper::F_V, float(fv->value()));

}

void paperSetting::createPaper() {

    paper pp;

    initPaper(pp);
    srand(time(0));

    int w = pp[paper::W], h = pp[paper::H];
    float** p = new float*[w];

    if (newFname.isEmpty())
        for (int x = 0; x < w; ++x) {
            p[x] = new float[h];
            for (int y = 0; y < h; ++y)
                p[x][y] = float(rand()) / float(RAND_MAX);
        }
    else {
        QImage img(newFname);
        for (int x = 0, i = 0; x < w; ++x, ++i) {
            p[x] = new float[h];
            i = i >= img.width() ? 0 : i;
            for (int y = 0, j = 0; y < h; ++y, ++j) {
                j = j >= img.height() ? 0 : j;
                p[x][y] = float(qGray(img.pixel(i, j))) / 255;
            }
        }
    }

    pp.init(w, h, p);

    for (int x = 0; x < w; ++x)
        delete[] p[x];
    delete[] p;

    emit readyPaper(pp);
    emit valueChanged(false);
    oldFname = newFname;


}

void paperSetting::setURL() {

    newFname = QFileDialog::getOpenFileName(this,
               tr("Open Image"), ".",
               tr("All files(*.*);;MBP(*.bmp);;JPG(*.jpg);;PNG(*.png);;GIF(*.gif)"));
    url->setText(newFname);

}

void paperSetting::delURL() {

    newFname = "";
    url->setText(newFname);

}

void paperSetting::reset(paper &pp) {

    width->setValue(int(pp[paper::W]));
    height->setValue(int(pp[paper::H]));
    pw->setValue(double(pp[paper::P_W]));
    pm->setValue(double(pp[paper::P_M]));
    fs->setValue(int(pp[paper::F_S]));
    fv->setValue(int(pp[paper::F_V]));
    url->setText(oldFname);
    newFname = oldFname;
    emit valueChanged(false);

}

