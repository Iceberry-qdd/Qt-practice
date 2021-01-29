#include "MyWidget.h"
#include <QPushButton>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* button = new QPushButton(this);
    button->setObjectName("myButton");
    button->setText(QString::fromLocal8Bit("关闭"));
    ui.setupUi(this);
}

void MyWidget::on_myButton_clicked()//自动关联
{
    close();
}