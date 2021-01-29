#include "MyWidget.h"
#include "MyDialog.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    MyDialog dialog;
    if (dialog.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else return a.exec();
}