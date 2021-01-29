#include<QKeyEvent>
#include<QDebug>
#include"MyLineEdit.h"

MyLineEdit::MyLineEdit(QWidget* parent) :QLineEdit(parent)
{
}

bool MyLineEdit::event(QEvent* event)
{
	if (event->type()==QEvent::KeyPress)
	{
		qDebug() << QString::fromLocal8Bit("MyLineEdit的event()函数");
	}
	return QLineEdit::event(event);
}

void MyLineEdit::keyPressEvent(QKeyEvent* event)
{
	qDebug() << QString::fromLocal8Bit("MyLineEdit键盘按下事件");
	QLineEdit::keyPressEvent(event);
	event->ignore();
}