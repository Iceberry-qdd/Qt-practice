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
    //颜色对话框
    void on_pushButton_6_clicked();
    //文件对话框
    void on_pushButton_2_clicked();
    //字体对话框
    void on_pushButton_8_clicked();
    //输入对话框
    void on_pushButton_4_clicked();
    //消息对话框
    void on_pushButton_5_clicked();
    //进度对话框
    void on_pushButton_clicked();
    //错误信息对话框
    void on_pushButton_7_clicked();
    //向导对话框
    void on_pushButton_3_clicked();

private:
    Ui::MyWidgetClass *ui;
    QErrorMessage* errordlg;

    QWizardPage* createPage1();//新添加
    QWizardPage* createPage2();//新添加
    QWizardPage* createPage3();//新添加
};
#endif // MYWIDGET_H