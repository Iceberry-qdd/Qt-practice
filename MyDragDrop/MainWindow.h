#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

protected:
    void dragEnterEvent(QDragEnterEvent* event);//拖入事件
    void dropEvent(QDropEvent* event);//放下事件

private:
    Ui::MainWindowClass ui;
};
