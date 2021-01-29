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
		qDebug() << QString::fromLocal8Bit("MyLineEdit��event()����");
	}
	return QLineEdit::event(event);
}

void MyLineEdit::keyPressEvent(QKeyEvent* event)
{
	qDebug() << QString::fromLocal8Bit("MyLineEdit���̰����¼�");
	QLineEdit::keyPressEvent(event);
	event->ignore();
}