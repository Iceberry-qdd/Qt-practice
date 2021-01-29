#include "MyWidget.h"
#include "ui_MyWidget.h"

MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent),
    ui(new Ui::MyWidgetClass)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit->setDisplayFormat(QString::fromLocal8Bit("yyyy年MM月dd日dddHH时mm分ss秒"));

}
