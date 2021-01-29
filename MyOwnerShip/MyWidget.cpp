#include "MyWidget.h"
#include "MyButton.h"
#include <qDebug>
#include <QHBoxLayout>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    ui->setupUi(this);

    MyButton* button = new MyButton(this);
    button->setText(QString::fromLocal8Bit("button"));

    MyButton* button2 = new MyButton;
    MyButton* button3 = new MyButton;
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(button2);
    layout->addWidget(button3);
    setLayout(layout);
    qDebug() << "[qDebug]" << children();
}

MyWidget::~MyWidget()
{
    delete ui;
    qDebug() << "[qDebug]delete widget";
}
