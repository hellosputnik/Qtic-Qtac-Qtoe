#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tic-tac-toe.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    TicTacToe* game;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_newGameButton_clicked();
    void on_NWButton_clicked();
    void on_NButton_clicked();
    void on_NEButton_clicked();
    void on_WButton_clicked();
    void on_CButton_clicked();
    void on_EButton_clicked();
    void on_SWButton_clicked();
    void on_SButton_clicked();
    void on_SEButton_clicked();

private:

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
