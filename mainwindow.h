#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_about_triggered();

    void on_action_find_triggered();

    void on_action_replace_triggered();

    void on_actionNew_triggered();

    void on_action_Open_triggered();

    void on_action_Save_triggered();

    void on_action_Othersave_triggered();

    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;

    QLabel statusCursorlabel;
    QLabel statusLabel;
    QString filepath; //记录打开的文件
    bool textchanged; //记录文本编辑改变

    bool userEditConfirmed();
};

#endif // MAINWINDOW_H
