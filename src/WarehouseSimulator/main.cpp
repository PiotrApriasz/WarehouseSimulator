#include <QApplication>
#include <QPushButton>
#include "qtWidgetUI/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow mw;
    mw.show();
    return QApplication::exec();
}
