#include "MyWidget.h"
#include "ui_MyWidget.h"
#include<QDialog>

MyWidget::MyWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MyWidgetClass)
{
    ui->setupUi(this);
    //connect(ui->showChildButton, &QPushButton::clicked, this, &MyWidget::showChildDialog);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_showChildButton_clicked()
{
    QDialog* dialog = new QDialog(this);
    dialog->show();
}