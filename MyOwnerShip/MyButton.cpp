#include "MyButton.h"
#include <QDebug>

MyButton::MyButton(QWidget* parent) : QPushButton(parent)
{
	
}

MyButton::~MyButton()
{
	qDebug() << "[qDebug]delete button";
}