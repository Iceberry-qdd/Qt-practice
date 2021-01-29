#include "MyWidget.h"
#include<QDebug>
#include<QTimerEvent>
#include<QTimer>
#include<QTime>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    id1 = startTimer(1000);
    id2 = startTimer(1500);
    id3 = startTimer(2200);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MyWidget::timerUpdate);
    timer->start(1000);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QTimer::singleShot(10000, this, &MyWidget::close);
}

void MyWidget::timerEvent(QTimerEvent* event)
{
    if (event->timerId()==id1)
    {
        qDebug() << "[qDebug]" << "timer1";
    }
    else if (event->timerId()==id2)
    {
        qDebug() << "[qDebug]" << "timer2";
    }
    else {
        qDebug() << "[qDebug]" << "timer3";
    }
}

void MyWidget::timerUpdate()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if (time.second()%2==0)
    {
        text[2] = ' ';
    }
    ui.lcdNumber->display(text);
    int rand = qrand() % 300;
    ui.lcdNumber->move(rand,rand);
}