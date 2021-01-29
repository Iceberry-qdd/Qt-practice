#ifndef MYDIALOG_H
#define MYDIALOG_H

#include<QDialog>
#include"ui_MyDialog.h"

class MyDialog : public QDialog
{
	Q_OBJECT

public:
	MyDialog(QWidget* parent = nullptr);

private:
	Ui::Dialog ui;

signals:
	void dlgReturn(int);

private slots:
	void on_pushButton_clicked();
};
#endif // !MYDIALOG_H