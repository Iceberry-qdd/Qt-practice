#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QtWidgets/QDialog>
//#include "ui_mydialog.h"

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget* parent = Q_NULLPTR);
    ~MyDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog* ui;
};

#endif // MYDIALOG_H