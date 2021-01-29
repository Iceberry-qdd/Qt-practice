#include "MyWidget.h"
#include<QMouseEvent>
#include<QApplication>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    setCursor(cursor);
    setMouseTracking(true);
}

void MyWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button()==Qt::LeftButton)
    {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos() - pos();
    }
    else if (event->button()==Qt::RightButton)
    {
        QCursor cursor(QPixmap("../MyMouseEvent/logo.png"));
        QApplication::setOverrideCursor(cursor);
    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();
}

void MyWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button()==Qt::LeftButton)
    {
        setWindowState(windowState() != Qt::WindowFullScreen ? Qt::WindowFullScreen : Qt::WindowNoState);
        /*
        if (windowState() != Qt::WindowFullScreen)
        {
            setWindowState(Qt::WindowFullScreen);
        }
        else {
            setWindowState(Qt::WindowNoState);
        }
        */
    }
}

void MyWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QPoint temp;
        temp = event->globalPos() - pos();
        move(temp);
    }
}

void MyWidget::wheelEvent(QWheelEvent* event)
{
    event->delta() > 0 ? ui.textEdit->zoomIn() : ui.textEdit->zoomOut();
}
