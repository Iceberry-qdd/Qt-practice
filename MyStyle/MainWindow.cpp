#include "MainWindow.h"
#include <QStyleFactory>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.progressBar->setStyle(QStyleFactory::create("windows"));

    QPalette palette1 = ui.pushButton->palette();
    palette1.setColor(QPalette::ButtonText, Qt::red);
    palette1.setColor(QPalette::Button, Qt::green);
    ui.spinBox->setDisabled(true);
    QPalette palette2 = ui.spinBox->palette();
    palette2.setColor(QPalette::Disabled, QPalette::Base, Qt::blue);
    ui.spinBox->setPalette(palette2);
}
