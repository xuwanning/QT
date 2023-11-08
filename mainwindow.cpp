#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "aboutwithoutbuttondialog.h"
#include "replacedialog.h"
#include "QFileDialog"
#include "QTextStream"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);  //主界面设计完成GG
    textchanged=false;
    on_actionNew_triggered();


    statusLabel.setMaximumWidth(150);
    statusLabel.setText("length:   "+QString::number(0)+"lines:    "+QString::number(1));
    ui->statusBar->addPermanentWidget(&statusLabel);

    statusCursorlabel.setMaximumWidth(150);
    statusCursorlabel.setText("Ln: "+QString::number(0)+"Col: "+QString::number(1));
    ui->statusBar->addPermanentWidget(&statusLabel);

    QLabel *author = new QLabel(ui->statusBar);
    author->setText(tr("孙家兴"));
    ui->statusBar->addPermanentWidget(author);

    ui->action_copy->setEnabled(false);
    ui->action_cut->setEnabled(false);
    ui->action_paste->setEnabled(false);
    ui->action_revoke->setEnabled(false);
    ui->action_restore->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_about_triggered()
{
    aboutDialog dlg;
    dlg.exec();
}

void MainWindow::on_action_find_triggered()
{
    aboutwithoutbuttonDialog dlg;
    dlg.exec();
}

void MainWindow::on_action_replace_triggered()
{
    replaceDialog dlg;
    dlg.exec();
}

void MainWindow::on_actionNew_triggered()   //新建
{
    if(!userEditConfirmed())
    {
        return;
    }
    filepath="";
    ui->textEdit->clear();
    this->setWindowTitle(tr("新建文本文件-编辑器"));
    textchanged=false;
}

void MainWindow::on_action_Open_triggered() //打开
{
    if(!userEditConfirmed())
    {
        return;
    }
    QString filename=QFileDialog::getOpenFileName(this,"打开文件",".",tr("Text file (*.txt) ;; All (*.*)"));
    QFile file(filename);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"..","打开文件失败");
        return;
    }
    filepath =filename;

    QTextStream in(&file);
    QString text=in.readAll();
    ui->textEdit->insertPlainText(text);
    file.close();

    this->setWindowTitle(QFileInfo(filename).absoluteFilePath());
    textchanged=false;
}

void MainWindow::on_action_Save_triggered()  //保存
{
    if(filepath=="")
    {
        QString filename=QFileDialog::getSaveFileName(this,"保存文件",".",tr("Text file (*.txt)"));
        QFile file(filename);
        if(!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this,"..","保存文件失败");
            return;
        }
        file.close();
        filepath =filename;
    }

    QFile file(filepath);              //考虑如果没有新建

//    if(!file.open(QFile::WriteOnly | QFile::Text))
//    {
//        QMessageBox::warning(this,"..","打开文件失败");

//        QString filename=QFileDialog::getSaveFileName(this,"保存文件",".",tr("Text file (*.txt)"));
//        QFile file(filename);
//        if(!file.open(QFile::WriteOnly | QFile::Text))
//        {
//            QMessageBox::warning(this,"..","保存文件失败");
//            return;
//        }
//        filepath =filename;
//    }
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"..","打开保存文件失败");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();

    this->setWindowTitle(QFileInfo(filepath).absoluteFilePath());
    textchanged=false;
}

void MainWindow::on_action_Othersave_triggered() //另存为
{
    QString filename=QFileDialog::getSaveFileName(this,"保存文件",".",tr("Text file (*.txt)"));
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"..","打开保存文件失败");
        return;
    }
    filepath =filename;
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();

    this->setWindowTitle(QFileInfo(filepath).absoluteFilePath());
}

void MainWindow::on_textEdit_textChanged()
{
    if(!textchanged)
    {
        this->setWindowTitle("*" + this->windowTitle());
        textchanged=true;
    }
}

bool MainWindow::userEditConfirmed()
{
    if(textchanged)
    {
        QString path=filepath !=""? filepath:"无标题.txt";
        QMessageBox msg(this);
        msg.setIcon(QMessageBox::Question);
        msg.setWindowTitle("...");
        msg.setText(QString("是否将更改保存到\n")+"\""+path+"\" ?");
        msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        int r=msg.exec();
        switch (r) {
        case QMessageBox::Yes:
            on_action_Save_triggered();
            break;
        case QMessageBox::No:
            textchanged=false;
            break;
        case QMessageBox::Cancel:
            return false;
        }
    }
    return true;
}
// 复制 剪切+

void MainWindow::on_action_revoke_triggered()  //恢复
{
    ui->textEdit->redo();
}

void MainWindow::on_action_cut_triggered()
{
    ui->textEdit->cut();
    ui->action_paste->setEnabled(true);
}

void MainWindow::on_action_copy_triggered()
{
    ui->textEdit->copy();
    ui->action_paste->setEnabled(true);
}

void MainWindow::on_action_paste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_action_restore_triggered() //撤销
{
    ui->textEdit->undo();
}

void MainWindow::on_textEdit_undoAvailable(bool b)
{
    ui->action_restore->setEnabled(b);
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->action_copy->setEnabled(b);
    ui->action_cut->setEnabled(b);
}

void MainWindow::on_textEdit_redoAvailable(bool b)
{
    ui->action_revoke->setEnabled(b);
}
