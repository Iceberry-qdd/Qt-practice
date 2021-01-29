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
    //QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("文件对话框"), "D:", QString::fromLocal8Bit("图片文件(*png *jpg);;文本文件(*txt)"));//选择单个文件
    QStringList fileNames = QFileDialog::getOpenFileNames(this, 
                                                          QString::fromLocal8Bit("文件对话框"), 
                                                          "D:", 
                                                          QString::fromLocal8Bit("图片文件(*png *jpg)"));
    qDebug() << "fileName:" << fileNames;
}

void MyWidget::on_pushButton_8_clicked()
{
    bool ok;//标记是否单击的OK按钮
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok)
    {
        ui->pushButton_8->setFont(font);
    }else
    {
        qDebug() << QString::fromLocal8Bit("没有选择字体！");
    }
}

void MyWidget::on_pushButton_4_clicked()
{
    bool ok;
    //获取字符串
    QString string=QInputDialog::getText(this, //指定父窗口
                                         QString::fromLocal8Bit("输入字符串对话框"), //设置窗口标题
                                         QString::fromLocal8Bit("请输入用户名："), //设置对话框中的标签显示文本
                                         QLineEdit::Normal, //设置输入字符串的显示模式
                                         QString::fromLocal8Bit("admin"), &ok);//设置是否按下ok
    if (ok)
    {
        qDebug() << "[qDebug]string:" << string;
    }
    int value1 = QInputDialog::getInt(this, //指定父窗口
                                      QString::fromLocal8Bit("输入整数对话框"), //设置窗口标题
                                      QString::fromLocal8Bit("请输入-1000到1000之间的整数"), //设置对话框中的标签显示文本
                                      100, //默认值
                                      -1000, //最小值
                                      1000, //最大值
                                      10, //若使用箭头按钮，每次数值变化10
                                      &ok);
    if (ok)
    {
        qDebug() << "[qDebug]value1:" << value1;
    }
    double value2 = QInputDialog::getDouble(this, 
                                            QString::fromLocal8Bit("输入浮点数对话框"),
                                            QString::fromLocal8Bit("请输入-1000到1000之间的浮点数"),
                                            0.00,
                                            -1000,
                                            1000,
                                            2,//小数位数
                                            &ok);
    if (ok)
    {
        qDebug() << "[qDebug]value2:" << value2;
    }
    QStringList items;
    items << QString::fromLocal8Bit("条目1") << QString::fromLocal8Bit("条目2");
    QString item = QInputDialog::getItem(this,
                                         QString::fromLocal8Bit("输入条目对话框"),
                                         QString::fromLocal8Bit("请选择或输入一个条目"),
                                         items,
                                         0,//默认显示列表中的第0个条目
                                         true,//条目是否可以被更改
                                         &ok);
    if (ok)
    {
        qDebug() << "[qDebug]item:" << item;
    }
}

void MyWidget::on_pushButton_5_clicked()
{
    //问题对话框
    int ret1 = QMessageBox::question(this,
                                     QString::fromLocal8Bit("问题对话框"),
                                     QString::fromLocal8Bit("你了解Qt吗？"),
                                     QMessageBox::Yes,
                                     QMessageBox::No);
    if (ret1==QMessageBox::Yes)
    {
        qDebug() << "[qDebug]:" << QString::fromLocal8Bit("问题！");
    }
    int ret2 = QMessageBox::information(this,
                                        QString::fromLocal8Bit("提示对话框"),
                                        QString::fromLocal8Bit("这是Qt书籍！"),
                                        QMessageBox::Ok);
    if (ret2 == QMessageBox::Ok)
    {
        qDebug() << "[qDebug]:" << QString::fromLocal8Bit("提示！");
    }
    int ret3 = QMessageBox::warning(this,
        QString::fromLocal8Bit("警告对话框"),
        QString::fromLocal8Bit("不能提前结束！"),
        QMessageBox::Abort);
    if (ret3 == QMessageBox::Abort)
    {
        qDebug() << "[qDebug]:" << QString::fromLocal8Bit("警告！");
    }
    int ret4 = QMessageBox::critical(this,
        QString::fromLocal8Bit("严重错误对话框"),
        QString::fromLocal8Bit("发现一个严重错误！现在要关闭所有文件！"),
        QMessageBox::YesAll);
    if (ret4 == QMessageBox::YesAll)
    {
        qDebug() << "[qDebug]:" << QString::fromLocal8Bit("错误！");
    }
    QMessageBox::about(this,
        QString::fromLocal8Bit("关于对话框"),
        QString::fromLocal8Bit("iceberry致力于Qt及Qt Creator的普及工作！"));
}

void MyWidget::on_pushButton_clicked()
{
    QProgressDialog dialog(QString::fromLocal8Bit("文件复制进度"),//设置对话框标签内容
                           QString::fromLocal8Bit("取消"),//设置取消按钮显示文本
                           0,//最小值
                           50000,//最大值
                           this);
    dialog.setWindowTitle(QString::fromLocal8Bit("进度对话框"));//设置窗口标题
    dialog.setWindowModality(Qt::WindowModal);//将对话框设为模态
    dialog.show();
    for (int i = 0; i < 50000; i++)//演示复制进度
    {
        dialog.setValue(i);//设置当前进度条的值
        QCoreApplication::processEvents();//避免界面冻结
        if (dialog.wasCanceled())
        {
            break;//按下取消按钮，则中断下载
        }
    }
    dialog.setValue(50000);//这样才能显示100%，因为for循环少加了一个数
    qDebug() << QString::fromLocal8Bit("[qDebug]复制结束！");
}

void MyWidget::on_pushButton_7_clicked()
{
    errordlg->setWindowTitle(QString::fromLocal8Bit("错误信息对话框"));
    errordlg->showMessage(QString::fromLocal8Bit("这里是出错信息！"));
}

void MyWidget::on_pushButton_3_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(QString::fromLocal8Bit("向导对话框"));
    wizard.addPage(createPage1());//添加向导页面
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}

QWizardPage* MyWidget::createPage1()
{
    //向导页面1
    QWizardPage* page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("介绍"));
    return page;
}

QWizardPage* MyWidget::createPage2()
{
    //向导页面2
    QWizardPage* page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("用户选择信息"));
    return page;
}

QWizardPage* MyWidget::createPage3()
{
    //向导界面3
    QWizardPage* page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("结束"));
    return page;
}

void MyWidget::on_pushButton_6_clicked()
{
    /*
    * 通过静态函数直接显示对话框
    QColor color = QColorDialog::getColor(Qt::red, this, QString::fromLocal8Bit("颜色对话框"),QColorDialog::ShowAlphaChannel);
    qDebug() << "color:" << color;
    */

    
    //通过创建对象显示对话框
    QColorDialog dialog(Qt::red, this);//创建对象
    dialog.setWindowTitle(QString::fromLocal8Bit("颜色对话框"));
    dialog.setOption(QColorDialog::ShowAlphaChannel);//显示alpha选项
    dialog.exec();//以模态方式运行对话框
    QColor color = dialog.currentColor();//获取当前颜色
    qDebug() << "color:" << color;//输出颜色信息
}