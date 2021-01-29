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

    QMenu* editMenu = ui.menuBar->addMenu(QString::fromLocal8Bit("�༭(&E)"));
    QAction* action_Open = editMenu->addAction(
        QIcon(":/images/images/open.png"),
        QString::fromLocal8Bit("���ļ�(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    ui.mainToolBar->addAction(action_Open);

    QActionGroup* group = new QActionGroup(this);//����������
    QAction* action_L = group->addAction(QString::fromLocal8Bit("�����(&L)"));
    action_L->setCheckable(true);
    QAction* action_R = group->addAction(QString::fromLocal8Bit("�Ҷ���(&R)"));
    action_R->setCheckable(true);
    QAction* action_C = group->addAction(QString::fromLocal8Bit("���ж���(&C)"));
    action_C->setCheckable(true);
    action_L->setChecked(true);
    editMenu->addSeparator();//��Ӽ����
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

    QToolButton* toolButton = new QToolButton(this);
    toolButton->setText(QString::fromLocal8Bit("��ɫ"));
    QMenu* colorMenu = new QMenu(this);
    colorMenu->addAction(QString::fromLocal8Bit("��ɫ"));
    colorMenu->addAction(QString::fromLocal8Bit("��ɫ"));
    toolButton->setMenu(colorMenu);
    toolButton->setPopupMode(QToolButton::MenuButtonPopup);//���õ���ģʽ
    ui.mainToolBar->addWidget(toolButton);
    QSpinBox* spinBox = new QSpinBox(this);
    ui.mainToolBar->addWidget(spinBox);
    
    //��ʾ��ʱ��Ϣ
    ui.statusBar->showMessage(QString::fromLocal8Bit("��ӭʹ�ö��ĵ��༭��"), 2000);
    //������ǩ�����ñ�ǩ��ʽ����ʾ��Ϣ��Ȼ���������ò�������ʽ��ӵ�״̬��
    QLabel* permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("www.qter.org");
    ui.statusBar->addPermanentWidget(permanent);
}

void MainWindow::on_action_New_triggered()
{
    QTextEdit* edit = new QTextEdit(this);
    //�����Ӵ��ڣ����ı��༭��Ϊ���Ĳ���
    QMdiSubWindow* child = ui.mdiArea->addSubWindow(edit);
    child->setWindowTitle(QString::fromLocal8Bit("���ĵ��༭���Ӵ���"));
    child->show();
}

void MainWindow::on_action_Dock_triggered()
{
    ui.dockWidget->show();
}