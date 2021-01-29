#include "MainWindow.h"
#include<QToolButton>
#include<QSpinBox>
#include<QTextEdit>
#include<QMdiSubWindow>
#include<QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QMenu* editMenu = ui.menuBar->addMenu(QString::fromLocal8Bit("编辑(&E)"));
    QAction* action_Open = editMenu->addAction(
        QIcon(":/images/images/open.png"),
        QString::fromLocal8Bit("打开文件(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    ui.mainToolBar->addAction(action_Open);

    QActionGroup* group = new QActionGroup(this);//建立动作组
    QAction* action_L = group->addAction(QString::fromLocal8Bit("左对齐(&L)"));
    action_L->setCheckable(true);
    QAction* action_R = group->addAction(QString::fromLocal8Bit("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction* action_C = group->addAction(QString::fromLocal8Bit("居中对齐(&C)"));
    action_C->setCheckable(true);
    action_L->setChecked(true);
    editMenu->addSeparator();//添加间隔器
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

    QToolButton* toolButton = new QToolButton(this);
    toolButton->setText(QString::fromLocal8Bit("颜色"));
    QMenu* colorMenu = new QMenu(this);
    colorMenu->addAction(QString::fromLocal8Bit("红色"));
    colorMenu->addAction(QString::fromLocal8Bit("绿色"));
    toolButton->setMenu(colorMenu);
    toolButton->setPopupMode(QToolButton::MenuButtonPopup);//设置弹出模式
    ui.mainToolBar->addWidget(toolButton);
    QSpinBox* spinBox = new QSpinBox(this);
    ui.mainToolBar->addWidget(spinBox);
    
    //显示临时消息
    ui.statusBar->showMessage(QString::fromLocal8Bit("欢迎使用多文档编辑器"), 2000);
    //创建标签，设置标签样式并显示信息，然后将其以永久部件的形式添加到状态栏
    QLabel* permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("www.qter.org");
    ui.statusBar->addPermanentWidget(permanent);
}

void MainWindow::on_action_New_triggered()
{
    QTextEdit* edit = new QTextEdit(this);
    //创建子窗口，以文本编辑器为中心部件
    QMdiSubWindow* child = ui.mdiArea->addSubWindow(edit);
    child->setWindowTitle(QString::fromLocal8Bit("多文档编辑器子窗口"));
    child->show();
}

void MainWindow::on_action_Dock_triggered()
{
    ui.dockWidget->show();
}