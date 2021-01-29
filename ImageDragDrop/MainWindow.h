#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWindowClass ui;

protected:
    void mousePressEvent(QMouseEvent* event);
    void dragEnterEvenet(QDragEnterEvent* event);
    void dragMoveEvenet(QDragMoveEvent* event);
    void dropEvent(QDropEvent* event);
};
