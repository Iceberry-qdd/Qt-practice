#include "MainWindow.h"
#include<QDragEnterEvent>
#include<QUrl>
#include<QFile>
#include<QTextStream>
#include<QMimeData>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	setAcceptDrops(true);
}

void MainWindow::dragEnterEvent(QDragEnterEvent* event)
{
	event->mimeData()->hasUrls() ? event->acceptProposedAction() : event->ignore();
}

void MainWindow::dropEvent(QDropEvent* event)
{
	const QMimeData* mimeData = event->mimeData();
	if (mimeData->hasUrls())
	{
		QList<QUrl> urlList = mimeData->urls();
		QString fileName = urlList.at(0).toLocalFile();
		if (!fileName.isEmpty())
		{
			QFile file(fileName);
			if (!file.open(QIODevice::ReadOnly)) return;
			QTextStream in(&file);
			ui.textEdit->setText(in.readAll());
		}
	}
}
