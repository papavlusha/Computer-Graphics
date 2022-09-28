#include "widget.h"

#include <QApplication>
#include <QStyleFactory>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    qApp->setStyle(QStyleFactory::create("Fusion"));

    Widget w;
    w.show();

    return a.exec();
}
