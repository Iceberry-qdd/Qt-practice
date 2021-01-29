#pragma once

#include <QtWidgets/QDialog>
#include "ui_HelloDialog.h"

class HelloDialog : public QDialog
{
    Q_OBJECT

public:
    HelloDialog(QWidget *parent = Q_NULLPTR);

private:
    Ui::HelloDialogClass ui;
};
