#include "MyWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.setWindowTitle(QString::fromLocal8Bit("��¼"));
    w.show();
    return a.exec();
}
