#include "MyWidget.h"
#include "ui_MyWidget.h"
#include<QDebug>
#include<QMenu>

MyWidget::MyWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MyWidgetClass)
{
    ui->setupUi(this);
    ui->pushBtn1->setText(tr("&nihao"));
    ui->pushBtn2->setText(QString::fromLocal8Bit("帮助(&H)"));
    ui->pushBtn2->setIcon(QIcon("../MyButton/help.png"));
    ui->pushBtn3->setText(tr("z&oom"));
    QMenu* menu = new QMenu(this);
    menu->addAction(QIcon("../MyButton/zoom-in.png"), QString::fromLocal8Bit("放大"));
    ui->pushBtn3->setMenu(menu);
}

MyWidget::~MyWidget()
{
    delete ui;
}
void MyWidget::on_pushBtn1_toggled(bool checked)
{
    qDebug() <<"[qDebug]"<< QString::fromLocal8Bit("按钮是否被按下：") << checked;
}
