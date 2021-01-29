#include "Widget.h"
#include<QKeyEvent>
#include<QDebug>
#include"MyLineEdit.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    lineEdit = new MyLineEdit(this);
    lineEdit->move(100, 100);

    lineEdit->installEventFilter(this);
}

bool Widget::eventFilter(QObject* obj, QEvent* event)
{
    if (obj == lineEdit)
    {
        if (event->type() == QEvent::KeyPress)
        {
            qDebug() << QString::fromLocal8Bit("Widget的事件过滤器");
        }
        return QWidget::eventFilter(obj, event);
    }
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    qDebug() << QString::fromLocal8Bit("Widget键盘按下事件");
}
