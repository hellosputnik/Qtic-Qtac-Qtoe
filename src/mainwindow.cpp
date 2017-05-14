#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Qt-related initialization code.
    ui->setupUi(this);

    // Create a new game board. This game board will be managed by the
    // Tic-Tac-Toe instance.
    GameBoard *board = new GameBoard();

    // Set each slot/space on the game board to a button.
    board->northwest = ui->NWButton;
    board->north     = ui->NButton;
    board->northeast = ui->NEButton;
    board->west      = ui->WButton;
    board->center    = ui->CButton;
    board->east      = ui->EButton;
    board->southwest = ui->SWButton;
    board->south     = ui->SButton;
    board->southeast = ui->SEButton;

    // Initialize the vector of slots/spaces.
    board->Initialize();

    // Create a new Tic-Tac-Toe instance.
    game = new TicTacToe(ui->newGameButton, board);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newGameButton_clicked()
{
    game->NewGame();
}

void MainWindow::on_NWButton_clicked()
{
    ui->NWButton->setText(game->GetCurrentPlayer());
    ui->NWButton->setEnabled(false);
    game->CheckWinCondition();
    game->ChangeTurn();
}

void MainWindow::on_NButton_clicked()
{
    ui->NButton->setText(game->GetCurrentPlayer());
    ui->NButton->setEnabled(false);
    game->CheckWinCondition();
    game->ChangeTurn();
}

void MainWindow::on_NEButton_clicked()
{
    ui->NEButton->setText(game->GetCurrentPlayer());
    ui->NEButton->setEnabled(false);

    game->CheckWinCondition();
    game->ChangeTurn();
}

void MainWindow::on_WButton_clicked()
{
    ui->WButton->setText(game->GetCurrentPlayer());
    ui->WButton->setEnabled(false);
    game->CheckWinCondition();
    game->ChangeTurn();
}

void MainWindow::on_CButton_clicked()
{
    ui->CButton->setText(game->GetCurrentPlayer());
    ui->CButton->setEnabled(false);
    game->CheckWinCondition();
    game->ChangeTurn();
}

void MainWindow::on_EButton_clicked()
{
    ui->EButton->setText(game->GetCurrentPlayer());
    ui->EButton->setEnabled(false);
    game->CheckWinCondition();
    game->ChangeTurn();
}

void MainWindow::on_SWButton_clicked()
{
    ui->SWButton->setText(game->GetCurrentPlayer());
    ui->SWButton->setEnabled(false);
    game->CheckWinCondition();
    game->ChangeTurn();
}

void MainWindow::on_SButton_clicked()
{
    ui->SButton->setText(game->GetCurrentPlayer());
    ui->SButton->setEnabled(false);
    game->CheckWinCondition();
    game->ChangeTurn();
}

void MainWindow::on_SEButton_clicked()
{
    ui->SEButton->setText(game->GetCurrentPlayer());
    ui->SEButton->setEnabled(false);
    game->CheckWinCondition();
    game->ChangeTurn();
}
