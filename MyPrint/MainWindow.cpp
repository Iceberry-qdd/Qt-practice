#include "MainWindow.h"
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrintPreviewDialog>
#include<QFileDialog>
#include<QFileInfo>
#include<QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QAction* action_print = new QAction(QString::fromLocal8Bit("打印"), this);
    QAction* action_printPreview = new QAction(QString::fromLocal8Bit("打印预览"), this);
    QAction* action_pdf = new QAction(QString::fromLocal8Bit("生成pdf"), this);
    connect(action_print, SIGNAL(triggered()), this, SLOT(doPrint()));
    connect(action_printPreview, SIGNAL(triggered()), this, SLOT(doPrintPreview()));
    connect(action_pdf, SIGNAL(triddered()), this, SLOT(createPdf()));
    ui.mainToolBar->addAction(action_print);
    ui.mainToolBar->addAction(action_printPreview);
    ui.mainToolBar->addAction(action_pdf);
}

void MainWindow::doPrint()
{
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    if (ui.textEdit->textCursor().hasSelection())
    {
        dlg.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    }
    if (dlg.exec()==QDialog::Accepted)
    {
        ui.textEdit->print(&printer);
    }
}

void MainWindow::doPrintPreview()
{
    QPrinter printer;
    QPrintPreviewDialog preview(&printer, this);
    connect(&preview, &QPrintPreviewDialog::paintRequested, this, &MainWindow::printPreview);
    preview.exec();
}

void MainWindow::printPreview(QPrinter* printer)
{
    ui.textEdit->print(printer);
}

void MainWindow::createPdf()
{
    QString fileName = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("导出PDF文件"), QString(), "*.pdf");
    if (!fileName.isEmpty())
    {
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
            QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);
            ui.textEdit->print(&printer);
        }
    }
}
