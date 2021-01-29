#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"

class MyLineEdit;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = Q_NULLPTR);
    bool eventFilter(QObject* obj, QEvent* event);

private:
    Ui::WidgetClass ui;
    MyLineEdit* lineEdit;

protected:
    void keyPressEvent(QKeyEvent* event);
};
