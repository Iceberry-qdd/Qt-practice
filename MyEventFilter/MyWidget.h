#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyWidget.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = Q_NULLPTR);
    bool eventFilter(QObject* obj, QEvent* event);

private:
    Ui::MyWidgetClass ui;
};
