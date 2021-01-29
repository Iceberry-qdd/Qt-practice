#include<QtWidgets/QApplication>
#include<QtWidgets/QWidget>
#include<QDebug>

/*
int main(int argc, char* argv[])
{
	QApplication qapp(argc, argv);
	QWidget widget;
	widget.show();
	int x = widget.x();
	int y = widget.y();
	QRect geometry = widget.geometry();
	QRect frame = widget.frameGeometry();
	return qapp.exec();
}
*/
int main(int argc, char* argv[])
{
	QApplication qapp(argc, argv);
	QWidget widget;
	//���ô��ڴ�С
	widget.resize(400, 300);
	//���ô���λ��
	widget.move(200, 100);
	widget.show();
	int x = widget.x();
	//���x��ֵ
	qDebug("x:%d", x);
	int y = widget.y();
	qDebug("y:%d", y);
	QRect geometry = widget.geometry();
	QRect frame = widget.frameGeometry();
	qDebug() << "geometry:" << geometry << "frame:" << frame;
	qDebug() << "pos:" << widget.pos() << endl
		<< "rect:" << widget.rect() << endl
		<< "size:" << widget.size() << endl
		<< "width:" << widget.width() << endl
		<< "height:" << widget.height();
	return qapp.exec();
}