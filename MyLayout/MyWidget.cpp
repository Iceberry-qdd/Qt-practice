#include "MyWidget.h"
#include<QHBoxLayout>
#include<QGridLayout>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    ui.textEdit->hide();
    /*
    * �������ֹ�����
    //�½�ˮƽ���ֹ�����
    QHBoxLayout* layout = new QHBoxLayout;
    //�򲼾ֹ���������Ӳ���
    layout->addWidget(ui.fontComboBox);
    layout->addWidget(ui.textEdit);
    //���ò�����ļ��
    layout->setSpacing(50);
    //���ò��ֹ��������߽�ľ���
    layout->setContentsMargins(0, 0, 50, 100);
    //���˲�������ΪMyWidget��Ĳ���
    setLayout(layout);
    */
    /*
    * դ�񲼾ֹ�����
    QGridLayout* layout = new QGridLayout;
    //��Ӳ������ӵ�0��0�п�ʼ��ռ��1��2��
    layout->addWidget(ui.fontComboBox, 0, 0, 1, 2);
    //��Ӳ������ӵ�0��2�п�ʼ��ռ��1��1��
    layout->addWidget(ui.pushButton, 0, 2, 1, 1);
    //��Ӳ������ӵ�1��0�п�ʼ��ռ��1��3��
    layout->addWidget(ui.textEdit, 1, 0, 1, 3);
    setLayout(layout);
    */

}
void MyWidget::on_pushButton_toggled(bool checked)
{
    //�����ı��༭������ʾ������
    ui.textEdit->setVisible(checked);
    if (checked)
    {
        ui.pushButton->setText(QString::fromLocal8Bit("���ؿ���չ����"));
    }
    else
    {
        ui.pushButton->setText(QString::fromLocal8Bit("��ʾ����չ����"));
    }
}