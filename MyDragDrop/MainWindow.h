#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

protected:
    void dragEnterEvent(QDragEnterEvent* event);//�����¼�
    void dropEvent(QDropEvent* event);//�����¼�

private:
    Ui::MainWindowClass ui;
};
