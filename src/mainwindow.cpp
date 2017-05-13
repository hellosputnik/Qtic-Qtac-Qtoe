#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // The game is disabled upon start.
    ui->NWButton->setEnabled(false);
    ui->NButton->setEnabled(false);
    ui->NEButton->setEnabled(false);
    ui->WButton->setEnabled(false);
    ui->CButton->setEnabled(false);
    ui->EButton->setEnabled(false);
    ui->SWButton->setEnabled(false);
    ui->SButton->setEnabled(false);
    ui->SEButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newGameButton_clicked()
{
    // The new game button is disabled as long as the game board is fresh.
    ui->newGameButton->setEnabled(false);

    // Clear the game board.
    ui->NWButton->setText("");
    ui->NWButton->setEnabled(true);
    ui->NButton->setText("");
    ui->NButton->setEnabled(true);
    ui->NEButton->setText("");
    ui->NEButton->setEnabled(true);
    ui->WButton->setText("");
    ui->WButton->setEnabled(true);
    ui->CButton->setText("");
    ui->CButton->setEnabled(true);
    ui->EButton->setText("");
    ui->EButton->setEnabled(true);
    ui->SWButton->setText("");
    ui->SWButton->setEnabled(true);
    ui->SButton->setText("");
    ui->SButton->setEnabled(true);
    ui->SEButton->setText("");
    ui->SEButton->setEnabled(true);
}

void MainWindow::on_NWButton_clicked()
{
    ui->NWButton->setText("X");
    ui->NWButton->setEnabled(false);

    ui->newGameButton->setEnabled(true);
}

void MainWindow::on_NButton_clicked()
{
    ui->NButton->setText("X");
    ui->NButton->setEnabled(false);

    ui->newGameButton->setEnabled(true);
}

void MainWindow::on_NEButton_clicked()
{
    ui->NEButton->setText("X");
    ui->NEButton->setEnabled(false);

    ui->newGameButton->setEnabled(true);
}

void MainWindow::on_WButton_clicked()
{
    ui->WButton->setText("X");
    ui->WButton->setEnabled(false);

    ui->newGameButton->setEnabled(true);
}

void MainWindow::on_CButton_clicked()
{
    ui->CButton->setText("X");
    ui->CButton->setEnabled(false);

    ui->newGameButton->setEnabled(true);
}

void MainWindow::on_EButton_clicked()
{
    ui->EButton->setText("X");
    ui->EButton->setEnabled(false);

    ui->newGameButton->setEnabled(true);
}

void MainWindow::on_SWButton_clicked()
{
    ui->SWButton->setText("X");
    ui->SWButton->setEnabled(false);

    ui->newGameButton->setEnabled(true);
}

void MainWindow::on_SButton_clicked()
{
    ui->SButton->setText("X");
    ui->SButton->setEnabled(false);

    ui->newGameButton->setEnabled(true);
}

void MainWindow::on_SEButton_clicked()
{
    ui->SEButton->setText("X");
    ui->SEButton->setEnabled(false);

    ui->newGameButton->setEnabled(true);
}
