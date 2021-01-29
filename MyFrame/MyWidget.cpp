#include "MyWidget.h"
#include "ui_MyWidget.h"
#include<QPixmap>
#include<QMovie>

MyWidget::MyWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MyWidgetClass)
{
    ui->setupUi(this);

    QFont font;
    font.setFamily(QString::fromLocal8Bit("华文行楷"));
    font.setPointSize(20);
    font.setBold(true);
    font.setItalic(true);
    ui->label->setFont(font);
    
    QString string = QString::fromLocal8Bit("标题太长，需要进行省略！");
    QString str = ui->label->fontMetrics().elidedText(string, Qt::ElideRight, 180);
    ui->label->setText(str);

    ui->label->setPixmap(QPixmap("C:/Users/Lenovo/Desktop/qt/03/3-8/logo.png"));

    QMovie* movie = new QMovie("C:/Users/Lenovo/Desktop/qt/03/3-8/donghua.gif");
    ui->label->setMovie(movie);
    movie->start();
}

MyWidget::~MyWidget()
{
    delete ui;
}
