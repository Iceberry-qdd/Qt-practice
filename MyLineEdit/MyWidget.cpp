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
    //�½���֤����ָ����ΧΪ100-999
    QValidator* validator = new QIntValidator(100, 999, this);

    //ʹ��������ʽ��֤
    QRegExp rx("-?\\d{1,3}");
    QValidator* validator2 = new QRegExpValidator(rx, this);

    //���б༭����ʹ����֤��
    ui->lineEdit3->setValidator(validator2);

    QStringList wordList;
    wordList << "Qt" << "Qt creator" << QString::fromLocal8Bit("���");
    //�½��Զ������
    QCompleter* completer = new QCompleter(wordList, this);
    //���ô�Сд������
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
