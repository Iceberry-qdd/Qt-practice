#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtWidgets/QWidget>
#include "ui_MyWidget.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = Q_NULLPTR);
    ~MyWidget();

private slots:
    void on_pushBtn1_toggled(bool checked);

private:
    Ui::MyWidgetClass* ui;
};

#endif // !MYWIDGET_H