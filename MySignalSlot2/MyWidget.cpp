#include "MyWidget.h"
#include <QPushButton>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* button = new QPushButton(this);
    button->setObjectName("myButton");
    button->setText(QString::fromLocal8Bit("�ر�"));
    ui.setupUi(this);
}

void MyWidget::on_myButton_clicked()//�Զ�����
{
    close();
}