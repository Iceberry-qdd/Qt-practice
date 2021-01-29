#include "MyWidget.h"
#include<QKeyEvent>
#include<QDebug>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	setFocus();
	keyUp = false;
	keyLeft = false;
	move = false;
}

void MyWidget::keyPressEvent(QKeyEvent* event)
{
	if (event->key()==Qt::Key_Up)
	{
		if (event->isAutoRepeat())
		{
			return;
		}
		else if (event->key()==Qt::Key_Left)
		{
			if (event->isAutoRepeat()) {
				return;
			}
			keyLeft = true;
		}
	}
}

void MyWidget::keyReleaseEvent(QKeyEvent* event)
{
	if (event->key()==Qt::Key_Up)
	{
		if (event->isAutoRepeat())
		{
			return;
		}
		keyUp = false;
		if (move)
		{
			move = false;
			return;
		}
		if (keyLeft)
		{
			ui.pushButton->move(30, 80);
			move = true;
		}
		else
		{
			ui.pushButton->move(120, 80);
		}
	}
	else if (event->key()==Qt::Key_Left)
	{
		if (event->isAutoRepeat())
		{
			return;
		}
		keyLeft = false;
		if (move)
		{
			move = false;
			return;
		}
		if (keyUp)
		{
			ui.pushButton->move(30, 80);
			move = true;
		}
		else
		{
			ui.pushButton->move(30, 120);
		}
	}
	else if (event->key()==Qt::Key_Down)
	{
		ui.pushButton->move(120, 120);
	}
}
