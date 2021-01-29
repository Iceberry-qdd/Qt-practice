#include <QtCore/QCoreApplication>
#include <QList>
#include <QDebug>

void print(QList<QString> list);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> list;
    list << "aa" << "bb" << "cc";
    if (list[1]=="bb")
    {
        list[1] = "ab";
    }
    list.replace(2, "bc");
    print(list);

    list.append("dd");
    list.append("mm");
    QString str = list.takeAt(2);
    print(list);

    list.insert(2, "mm");
    list.swap(1, 3);
    print(list);

    qDebug() << "[qDebug]contains 'mm'?" << list.contains("mm");
    qDebug() << "[qDebug]The 'mm' count:" << list.count("mm");
    qDebug() << "[qDebug]The first 'mm' index:" << list.indexOf("mm");
    qDebug() << "[qDebug]The second 'mm' index:" << list.indexOf("mm", 3);

    return a.exec();
}

void print(QList<QString> list)
{
    qDebug() << "[qDebug]The list is:";
    for (int i = 0; i < list.size(); ++i)
    {
        qDebug() << list.at(i);
    }
}