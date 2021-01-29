//#include<QtWidgets>
#include<QtWidgets/QApplication>
#include<QtWidgets/QWidget>
#include<QtWidgets/QLabel>

int main(int argc, char* argv[])
{
	QApplication qapp(argc, argv);
	QWidget* widget = new QWidget(0,Qt::Dialog|Qt::FramelessWindowHint);
	//widget->setWindowTitle(QString::fromUtf8("我是widget"));
	widget->setWindowTitle(QStringLiteral("我是widget"));
	QLabel* label = new QLabel(0,Qt::SplashScreen|Qt::WindowStaysOnTopHint);
	label->setWindowTitle(QStringLiteral("我是label"));
	label->setText(QStringLiteral("label:我是一个窗口"));
	label->resize(300, 80);
	QLabel* label2 = new QLabel(widget);
	label2->setText(QStringLiteral("label2:我不是独立窗口，只是widget的子部件"));
	label2->resize(400, 80);
	label->show();
	widget->show();
	int ret = qapp.exec();
	delete label;
	delete widget;
	return ret;
}