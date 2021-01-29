#include "MyWidget.h"
#include "ui_mywidget.h"
#include<QDebug>
#include<QColorDialog>
#include<QFileDialog>
#include<QFontDialog>
#include<QInputDialog>
#include<QMessageBox>
#include<QProgressDialog>
#include<QErrorMessage>

MyWidget::MyWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MyWidgetClass)
{
    ui->setupUi(this);
    errordlg = new QErrorMessage(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_2_clicked()
{
    //QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("�ļ��Ի���"), "D:", QString::fromLocal8Bit("ͼƬ�ļ�(*png *jpg);;�ı��ļ�(*txt)"));//ѡ�񵥸��ļ�
    QStringList fileNames = QFileDialog::getOpenFileNames(this, 
                                                          QString::fromLocal8Bit("�ļ��Ի���"), 
                                                          "D:", 
                                                          QString::fromLocal8Bit("ͼƬ�ļ�(*png *jpg)"));
    qDebug() << "fileName:" << fileNames;
}

void MyWidget::on_pushButton_8_clicked()
{
    bool ok;//����Ƿ񵥻���OK��ť
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok)
    {
        ui->pushButton_8->setFont(font);
    }else
    {
        qDebug() << QString::fromLocal8Bit("û��ѡ�����壡");
    }
}

void MyWidget::on_pushButton_4_clicked()
{
    bool ok;
    //��ȡ�ַ���
    QString string=QInputDialog::getText(this, //ָ��������
                                         QString::fromLocal8Bit("�����ַ����Ի���"), //���ô��ڱ���
                                         QString::fromLocal8Bit("�������û�����"), //���öԻ����еı�ǩ��ʾ�ı�
                                         QLineEdit::Normal, //���������ַ�������ʾģʽ
                                         QString::fromLocal8Bit("admin"), &ok);//�����Ƿ���ok
    if (ok)
    {
        qDebug() << "[qDebug]string:" << string;
    }
    int value1 = QInputDialog::getInt(this, //ָ��������
                                      QString::fromLocal8Bit("���������Ի���"), //���ô��ڱ���
                                      QString::fromLocal8Bit("������-1000��1000֮�������"), //���öԻ����еı�ǩ��ʾ�ı�
                                      100, //Ĭ��ֵ
                                      -1000, //��Сֵ
                                      1000, //���ֵ
                                      10, //��ʹ�ü�ͷ��ť��ÿ����ֵ�仯10
                                      &ok);
    if (ok)
    {
        qDebug() << "[qDebug]value1:" << value1;
    }
    double value2 = QInputDialog::getDouble(this, 
                                            QString::fromLocal8Bit("���븡�����Ի���"),
                                            QString::fromLocal8Bit("������-1000��1000֮��ĸ�����"),
                                            0.00,
                                            -1000,
                                            1000,
                                            2,//С��λ��
                                            &ok);
    if (ok)
    {
        qDebug() << "[qDebug]value2:" << value2;
    }
    QStringList items;
    items << QString::fromLocal8Bit("��Ŀ1") << QString::fromLocal8Bit("��Ŀ2");
    QString item = QInputDialog::getItem(this,
                                         QString::fromLocal8Bit("������Ŀ�Ի���"),
                                         QString::fromLocal8Bit("��ѡ�������һ����Ŀ"),
                                         items,
                                         0,//Ĭ����ʾ�б��еĵ�0����Ŀ
                                         true,//��Ŀ�Ƿ���Ա�����
                                         &ok);
    if (ok)
    {
        qDebug() << "[qDebug]item:" << item;
    }
}

void MyWidget::on_pushButton_5_clicked()
{
    //����Ի���
    int ret1 = QMessageBox::question(this,
                                     QString::fromLocal8Bit("����Ի���"),
                                     QString::fromLocal8Bit("���˽�Qt��"),
                                     QMessageBox::Yes,
                                     QMessageBox::No);
    if (ret1==QMessageBox::Yes)
    {
        qDebug() << "[qDebug]:" << QString::fromLocal8Bit("���⣡");
    }
    int ret2 = QMessageBox::information(this,
                                        QString::fromLocal8Bit("��ʾ�Ի���"),
                                        QString::fromLocal8Bit("����Qt�鼮��"),
                                        QMessageBox::Ok);
    if (ret2 == QMessageBox::Ok)
    {
        qDebug() << "[qDebug]:" << QString::fromLocal8Bit("��ʾ��");
    }
    int ret3 = QMessageBox::warning(this,
        QString::fromLocal8Bit("����Ի���"),
        QString::fromLocal8Bit("������ǰ������"),
        QMessageBox::Abort);
    if (ret3 == QMessageBox::Abort)
    {
        qDebug() << "[qDebug]:" << QString::fromLocal8Bit("���棡");
    }
    int ret4 = QMessageBox::critical(this,
        QString::fromLocal8Bit("���ش���Ի���"),
        QString::fromLocal8Bit("����һ�����ش�������Ҫ�ر������ļ���"),
        QMessageBox::YesAll);
    if (ret4 == QMessageBox::YesAll)
    {
        qDebug() << "[qDebug]:" << QString::fromLocal8Bit("����");
    }
    QMessageBox::about(this,
        QString::fromLocal8Bit("���ڶԻ���"),
        QString::fromLocal8Bit("iceberry������Qt��Qt Creator���ռ�������"));
}

void MyWidget::on_pushButton_clicked()
{
    QProgressDialog dialog(QString::fromLocal8Bit("�ļ����ƽ���"),//���öԻ����ǩ����
                           QString::fromLocal8Bit("ȡ��"),//����ȡ����ť��ʾ�ı�
                           0,//��Сֵ
                           50000,//���ֵ
                           this);
    dialog.setWindowTitle(QString::fromLocal8Bit("���ȶԻ���"));//���ô��ڱ���
    dialog.setWindowModality(Qt::WindowModal);//���Ի�����Ϊģ̬
    dialog.show();
    for (int i = 0; i < 50000; i++)//��ʾ���ƽ���
    {
        dialog.setValue(i);//���õ�ǰ��������ֵ
        QCoreApplication::processEvents();//������涳��
        if (dialog.wasCanceled())
        {
            break;//����ȡ����ť�����ж�����
        }
    }
    dialog.setValue(50000);//����������ʾ100%����Ϊforѭ���ټ���һ����
    qDebug() << QString::fromLocal8Bit("[qDebug]���ƽ�����");
}

void MyWidget::on_pushButton_7_clicked()
{
    errordlg->setWindowTitle(QString::fromLocal8Bit("������Ϣ�Ի���"));
    errordlg->showMessage(QString::fromLocal8Bit("�����ǳ�����Ϣ��"));
}

void MyWidget::on_pushButton_3_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(QString::fromLocal8Bit("�򵼶Ի���"));
    wizard.addPage(createPage1());//�����ҳ��
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}

QWizardPage* MyWidget::createPage1()
{
    //��ҳ��1
    QWizardPage* page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("����"));
    return page;
}

QWizardPage* MyWidget::createPage2()
{
    //��ҳ��2
    QWizardPage* page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("�û�ѡ����Ϣ"));
    return page;
}

QWizardPage* MyWidget::createPage3()
{
    //�򵼽���3
    QWizardPage* page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("����"));
    return page;
}

void MyWidget::on_pushButton_6_clicked()
{
    /*
    * ͨ����̬����ֱ����ʾ�Ի���
    QColor color = QColorDialog::getColor(Qt::red, this, QString::fromLocal8Bit("��ɫ�Ի���"),QColorDialog::ShowAlphaChannel);
    qDebug() << "color:" << color;
    */

    
    //ͨ������������ʾ�Ի���
    QColorDialog dialog(Qt::red, this);//��������
    dialog.setWindowTitle(QString::fromLocal8Bit("��ɫ�Ի���"));
    dialog.setOption(QColorDialog::ShowAlphaChannel);//��ʾalphaѡ��
    dialog.exec();//��ģ̬��ʽ���жԻ���
    QColor color = dialog.currentColor();//��ȡ��ǰ��ɫ
    qDebug() << "color:" << color;//�����ɫ��Ϣ
}