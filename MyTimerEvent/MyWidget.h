#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyWidget.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = Q_NULLPTR);

private:
    Ui::MyWidgetClass ui;
    int id1, id2, id3;

protected:
    void timerEvent(QTimerEvent* event);

private slots:
    void timerUpdate();
};
