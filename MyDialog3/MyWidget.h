#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtWidgets/QWidget>
#include "ui_MyWidget.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget* parent = Q_NULLPTR);
    ~MyWidget();

private:
    Ui::MyWidgetClass* ui;

public slots:
    void on_showChildButton_clicked();
};

#endif // MYWIDGET_H