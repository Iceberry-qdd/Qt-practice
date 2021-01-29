#include "MyDialog.h"

MyDialog::MyDialog(QWidget* parent) : QDialog(parent)
{
	ui.setupUi(this);
}

void MyDialog::on_pushButton_clicked()
{
	int value = ui.spinBox->value();
	emit dlgReturn(value);
	close();
}