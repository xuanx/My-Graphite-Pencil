#include <QApplication>
#include "appMainWindow.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    appMainWindow *appMain = new appMainWindow;

    appMain->show();

    return app.exec();
}
