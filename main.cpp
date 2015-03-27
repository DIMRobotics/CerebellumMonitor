#include "mainwindow.h"
#include <QApplication>

#include "QCerebellum/msgtypes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qRegisterMetaType<QCerebellum::PositionMessage>("QCerebellum::PositionMessage");

    return a.exec();
}
