#include "MyWidget.h"
#include "MyClass.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    MyClass* mCls = new MyClass(this);
    connect(mCls, &MyClass::userNameChanged, this, &MyWidget::userChanged);
    mCls->setUserName("Iceberry");//��������ֵ
    qDebug() << "[qDebug]userName1:" << mCls->getUserName();//�������ֵ
    mCls->setProperty("userName", "Linux");
    qDebug() << "[qDebug]userName2:" << mCls->property("userName").toString();

    mCls->setProperty("myValue", 10);
    qDebug() << "[qDebug]myValue:" << mCls->property("myValue").toInt();
}

void MyWidget::userChanged(QString userName)
{
    qDebug() << "[qDebug]user changed:" << userName;
}