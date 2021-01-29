#include "MyWidget.h"
#include "ui_MyWidget.h"
#include<QDialog>

MyWidget::MyWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MyWidgetClass)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}