#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtWidgets/QWidget>
#include "ui_MyWidget.h"
#include<QWizard>

class QErrorMessage;

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = Q_NULLPTR);
    ~MyWidget();

private slots:
    //��ɫ�Ի���
    void on_pushButton_6_clicked();
    //�ļ��Ի���
    void on_pushButton_2_clicked();
    //����Ի���
    void on_pushButton_8_clicked();
    //����Ի���
    void on_pushButton_4_clicked();
    //��Ϣ�Ի���
    void on_pushButton_5_clicked();
    //���ȶԻ���
    void on_pushButton_clicked();
    //������Ϣ�Ի���
    void on_pushButton_7_clicked();
    //�򵼶Ի���
    void on_pushButton_3_clicked();

private:
    Ui::MyWidgetClass *ui;
    QErrorMessage* errordlg;

    QWizardPage* createPage1();//�����
    QWizardPage* createPage2();//�����
    QWizardPage* createPage3();//�����
};
#endif // MYWIDGET_H