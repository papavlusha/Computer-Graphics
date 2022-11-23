#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    w.setWindowTitle("Лаба 4");
    w.setWindowIcon(QIcon("../lab4/icon.png"));
    w.show();
    return a.exec();
}
