#include "MyWidget.h"
#include "ui_MyWidget.h"
#include<QDialog>

MyWidget::MyWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MyWidgetClass)
{
    ui->setupUi(this);
    /*
    * 非模态对话框
    QDialog dialog(this);
    dialog.show();
    */

    /*
    * 非模态对话框
    QDialog* dialog = new QDialog(this);
    dialog->show();
    */

    /*
    * 模态对话框
    QDialog dialog(this);
    dialog.exec();
    */

    /*
    * 非模态对话框
    QDialog* dialog = new QDialog(this);
    dialog->setModal(true);
    dialog->show();
    */
}
