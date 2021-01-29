#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void on_action_New_triggered();
    void on_action_Dock_triggered();

private:
    Ui::MainWindowClass ui;
};
