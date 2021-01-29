#include "MyWidget.h"
#include "ui_MyWidget.h"
#include<QDialog>

MyWidget::MyWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MyWidgetClass)
{
    ui->setupUi(this);
    /*
    * ��ģ̬�Ի���
    QDialog dialog(this);
    dialog.show();
    */

    /*
    * ��ģ̬�Ի���
    QDialog* dialog = new QDialog(this);
    dialog->show();
    */

    /*
    * ģ̬�Ի���
    QDialog dialog(this);
    dialog.exec();
    */

    /*
    * ��ģ̬�Ի���
    QDialog* dialog = new QDialog(this);
    dialog->setModal(true);
    dialog->show();
    */
}
