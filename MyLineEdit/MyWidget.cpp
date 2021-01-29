#include "MyWidget.h"
#include "ui_MyWidget.h"
#include<QDebug>
#include<QValidator>
#include<QCompleter>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::MyWidgetClass)
{
    ui->setupUi(this);
    //新建验证器，指定范围为100-999
    QValidator* validator = new QIntValidator(100, 999, this);

    //使用正则表达式验证
    QRegExp rx("-?\\d{1,3}");
    QValidator* validator2 = new QRegExpValidator(rx, this);

    //在行编辑器中使用验证器
    ui->lineEdit3->setValidator(validator2);

    QStringList wordList;
    wordList << "Qt" << "Qt creator" << QString::fromLocal8Bit("你好");
    //新建自动完成器
    QCompleter* completer = new QCompleter(wordList, this);
    //设置大小写不敏感
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit4->setCompleter(completer);
}

void MyWidget::on_lineEdit2_returnPressed()
{
    ui->lineEdit3->setFocus();
    qDebug() << "[qDebug]" << ui->lineEdit2->text();
    qDebug() << "[qDebug]" << ui->lineEdit2->displayText();
}

void MyWidget::on_lineEdit3_returnPressed()
{
    ui->lineEdit4->setFocus();
    qDebug() << "[qDebug]" << ui->lineEdit3->text();
}
