#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyWidget.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = Q_NULLPTR);

private slots:
    void on_pushButton_toggled(bool checked);
private:
    Ui::MyWidgetClass ui;
};
