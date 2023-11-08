#include "aboutwithoutbuttondialog.h"
#include "ui_aboutwithoutbuttondialog.h"
#include <QMessageBox>

aboutwithoutbuttonDialog::aboutwithoutbuttonDialog(QWidget *parent,QPlainTextEdit * textEdit) :
    QDialog(parent),
    ui(new Ui::aboutwithoutbuttonDialog)
{
    ui->setupUi(this);

    pTextEdit=textEdit;

    ui->rBdown->setChecked(true);
}

aboutwithoutbuttonDialog::~aboutwithoutbuttonDialog()
{
    delete ui;
}

void aboutwithoutbuttonDialog::on_pushButton_8_clicked()
{

}

void aboutwithoutbuttonDialog::on_pushButton_5_clicked()  //查找下一个
{
    QString target=ui->secherlineEdit->text();
    QString text=pTextEdit->toPlainText();
    QTextCursor c=pTextEdit->textCursor();
    int index=-1;

    if(ui->rBdown->isChecked())
    {
        index=text.indexOf(target,c.position(),ui->checkBox_3->isChecked()? Qt::CaseSensitive : Qt::CaseSensitive);
        if(index>=0)
        {
            c.setPosition(index);
            c.setPosition(index+target.length(),QTextCursor::KeepAnchor);

            pTextEdit->setTextCursor(c);
        }
    }
    else if (ui->rBup->isChecked()) {
        index=text.lastIndexOf(target,c.position()-text.length()-1,ui->checkBox_3->isChecked()? Qt::CaseSensitive : Qt::CaseSensitive);
        if(index>=0)
        {
            c.setPosition(index+target.length());
            c.setPosition(index,QTextCursor::KeepAnchor);

            pTextEdit->setTextCursor(c);
        }
    }
    if(index<0)
    {
        QMessageBox msg(this);
        msg.setWindowTitle("记事本");
        msg.setText(QString("找不到")+target);
        msg.setWindowFlag(Qt::Drawer);
        msg.setIcon(QMessageBox::Information);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
}
