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
    game = new TicTacToe(ui->newGameButton, board, ui->label);
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
    Player player = game->GetCurrentPlayer();

    ui->NWButton->setText(player.character);
    ui->NWButton->setEnabled(false);
    ui->NWButton->setStyleSheet("color: " + player.color);

    game->ChangeTurn();
    game->CheckWinCondition();
}

void MainWindow::on_NButton_clicked()
{
    Player player = game->GetCurrentPlayer();

    ui->NButton->setText(player.character);
    ui->NButton->setEnabled(false);
    ui->NButton->setStyleSheet("color: " + player.color);

    game->ChangeTurn();
    game->CheckWinCondition();
}

void MainWindow::on_NEButton_clicked()
{
    Player player = game->GetCurrentPlayer();

    ui->NEButton->setText(player.character);
    ui->NEButton->setEnabled(false);
    ui->NEButton->setStyleSheet("color: " + player.color);

    game->ChangeTurn();
    game->CheckWinCondition();
}

void MainWindow::on_WButton_clicked()
{
    Player player = game->GetCurrentPlayer();

    ui->WButton->setText(player.character);
    ui->WButton->setEnabled(false);
    ui->WButton->setStyleSheet("color: " + player.color);

    game->ChangeTurn();
    game->CheckWinCondition();
}

void MainWindow::on_CButton_clicked()
{
    Player player = game->GetCurrentPlayer();

    ui->CButton->setText(player.character);
    ui->CButton->setEnabled(false);
    ui->CButton->setStyleSheet("color: " + player.color);

    game->ChangeTurn();
    game->CheckWinCondition();
}

void MainWindow::on_EButton_clicked()
{
    Player player = game->GetCurrentPlayer();

    ui->EButton->setText(player.character);
    ui->EButton->setEnabled(false);
    ui->EButton->setStyleSheet("color: " + player.color);

    game->ChangeTurn();
    game->CheckWinCondition();
}

void MainWindow::on_SWButton_clicked()
{
    Player player = game->GetCurrentPlayer();

    ui->SWButton->setText(player.character);
    ui->SWButton->setEnabled(false);
    ui->SWButton->setStyleSheet("color: " + player.color);

    game->ChangeTurn();
    game->CheckWinCondition();
}

void MainWindow::on_SButton_clicked()
{
    Player player = game->GetCurrentPlayer();

    ui->SButton->setText(player.character);
    ui->SButton->setEnabled(false);
    ui->SButton->setStyleSheet("color: " + player.color);

    game->ChangeTurn();
    game->CheckWinCondition();
}

void MainWindow::on_SEButton_clicked()
{
    Player player = game->GetCurrentPlayer();

    ui->SEButton->setText(player.character);
    ui->SEButton->setEnabled(false);
    ui->SEButton->setStyleSheet("color: " + player.color);

    game->ChangeTurn();
    game->CheckWinCondition();
}
