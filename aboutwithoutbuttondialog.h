#ifndef ABOUTWITHOUTBUTTONDIALOG_H
#define ABOUTWITHOUTBUTTONDIALOG_H

#include <QDialog>
#include<QPlainTextEdit>

namespace Ui {
class aboutwithoutbuttonDialog;
}

class aboutwithoutbuttonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit aboutwithoutbuttonDialog(QWidget *parent = nullptr,QPlainTextEdit * textEdit =nullptr);
    ~aboutwithoutbuttonDialog();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::aboutwithoutbuttonDialog *ui;

    QPlainTextEdit *pTextEdit;
};

#endif // ABOUTWITHOUTBUTTONDIALOG_H
