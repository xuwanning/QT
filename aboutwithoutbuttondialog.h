#ifndef ABOUTWITHOUTBUTTONDIALOG_H
#define ABOUTWITHOUTBUTTONDIALOG_H

#include <QDialog>

namespace Ui {
class aboutwithoutbuttonDialog;
}

class aboutwithoutbuttonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit aboutwithoutbuttonDialog(QWidget *parent = nullptr);
    ~aboutwithoutbuttonDialog();

private:
    Ui::aboutwithoutbuttonDialog *ui;
};

#endif // ABOUTWITHOUTBUTTONDIALOG_H
