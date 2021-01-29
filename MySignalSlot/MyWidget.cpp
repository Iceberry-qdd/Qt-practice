#include "MyWidget.h"
#include "MyDialog.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    MyDialog* dlg = new MyDialog(this);
    //connect(dlg, SIGNAL(dlgReturn(int)), this, SLOT(showValue(int)));
    connect(dlg, &MyDialog::dlgReturn, this, &MyWidget::showValue);
    dlg->show();
}

void MyWidget::showValue(int value)
{
    ui.label->setText(QString::fromLocal8Bit("获取的值是：%1").arg(value));
}