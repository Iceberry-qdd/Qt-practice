#ifndef MAINWINOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class QPrinter;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = Q_NULLPTR);

private slots:
    void doPrintPreview();
    void printPreview(QPrinter* printer);
    void createPdf();
    void doPrint();

private:
    Ui::MainWindowClass ui;
};
#endif // !MAINWINOW_H