#include "aboutwithoutbuttondialog.h"
#include "ui_aboutwithoutbuttondialog.h"

aboutwithoutbuttonDialog::aboutwithoutbuttonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutwithoutbuttonDialog)
{
    ui->setupUi(this);
}

aboutwithoutbuttonDialog::~aboutwithoutbuttonDialog()
{
    delete ui;
}
