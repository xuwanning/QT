#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);  //主界面设计完成



    statusLabel.setMaximumWidth(150);
    statusLabel.setText("length:   "+QString::number(0)+"lines:    "+QString::number(1));
    ui->statusBar->addPermanentWidget(&statusLabel);

    statusCursorlabel.setMaximumWidth(150);
    statusCursorlabel.setText("Ln: "+QString::number(0)+"Col: "+QString::number(1));
    ui->statusBar->addPermanentWidget(&statusLabel);

    QLabel *author = new QLabel(ui->statusBar);
    author->setText(tr("孙家兴"));
    ui->statusBar->addPermanentWidget(author);

}

MainWindow::~MainWindow()
{
    delete ui;
}
