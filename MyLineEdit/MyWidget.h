#ifndef MYWIGHT_H
#define MYWIDGET_H

#include <QtWidgets/QWidget>
#include "ui_MyWidget.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = Q_NULLPTR);

private slots:
    void on_lineEdit2_returnPressed();
    void on_lineEdit3_returnPressed();

private:
    Ui::MyWidgetClass* ui;
};

#endif // !MYWIGHT_H