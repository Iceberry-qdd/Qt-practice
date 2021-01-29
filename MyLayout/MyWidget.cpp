#include "MyWidget.h"
#include<QHBoxLayout>
#include<QGridLayout>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    ui.textEdit->hide();
    /*
    * 基本布局管理器
    //新建水平布局管理器
    QHBoxLayout* layout = new QHBoxLayout;
    //向布局管理器中添加部件
    layout->addWidget(ui.fontComboBox);
    layout->addWidget(ui.textEdit);
    //设置部件间的间隔
    layout->setSpacing(50);
    //设置布局管理器到边界的距离
    layout->setContentsMargins(0, 0, 50, 100);
    //将此布局设置为MyWidget类的布局
    setLayout(layout);
    */
    /*
    * 栅格布局管理器
    QGridLayout* layout = new QGridLayout;
    //添加部件，从第0行0列开始，占据1行2列
    layout->addWidget(ui.fontComboBox, 0, 0, 1, 2);
    //添加部件，从第0行2列开始，占据1行1列
    layout->addWidget(ui.pushButton, 0, 2, 1, 1);
    //添加部件，从第1行0列开始，占据1行3列
    layout->addWidget(ui.textEdit, 1, 0, 1, 3);
    setLayout(layout);
    */

}
void MyWidget::on_pushButton_toggled(bool checked)
{
    //设置文本编辑器的显示和隐藏
    ui.textEdit->setVisible(checked);
    if (checked)
    {
        ui.pushButton->setText(QString::fromLocal8Bit("隐藏可扩展窗口"));
    }
    else
    {
        ui.pushButton->setText(QString::fromLocal8Bit("显示可扩展窗口"));
    }
}