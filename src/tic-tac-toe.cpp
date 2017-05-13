// Qt headers
#include <QDebug>

// STL headers
#include <algorithm>

#include "tic-tac-toe.h"

TicTacToe::TicTacToe()
{
    new_game_button_ = nullptr;
    board_           = nullptr;
    turn_            = 0;
    players_[0]      = 'O';
    players_[1]      = 'X';
}

TicTacToe::TicTacToe(QPushButton *new_game_button, GameBoard* board)
{
    new_game_button_ = new_game_button;
    board_           = board;
    turn_            = 0;
    players_[0]      = 'O';
    players_[1]      = 'X';
}

TicTacToe::~TicTacToe()
{
    delete board_;
}

void TicTacToe::ChangeTurn()
{
    // XOR between player 0 and player 1.
    turn_ ^= 1;
}

bool TicTacToe::CheckWinCondition()
{
    // Check if there is a row that belongs to a single player.
    if (board_->northwest->text() == board_->north->text() &&
        board_->north->text() == board_->northeast->text())
        return true;
    if (board_->west->text() == board_->center->text() &&
        board_->center->text() == board_->east->text())
        return true;
    if (board_->southwest->text() == board_->south->text() &&
        board_->south->text() == board_->southeast->text())
        return true;

    // Check if there is a column that belongs to a single player.
    if (board_->northwest->text() == board_->west->text() &&
        board_->west->text() == board_->southwest->text())
        return true;
    if (board_->north->text() == board_->center->text() &&
        board_->center->text() == board_->south->text())
        return true;
    if (board_->northeast->text() == board_->east->text() &&
        board_->east->text() == board_->southeast->text())
        return true;

    // Check if a single player diagonally owns board spaces.
    if (board_->northwest->text() == board_->center->text() &&
        board_->center->text() == board_->southeast->text())
        return true;
    if (board_->northeast->text() == board_->center->text() &&
        board_->center->text() == board_->southwest->text())
        return true;

    return false;
}

QChar TicTacToe::GetCurrentPlayer()
{
    // Based on the turn, return the player's character.
    return players_[turn_];
}

void TicTacToe::NewGame()
{
    // Disable the new_game button.
    new_game_button_->setEnabled(false);

    // Clear the game board by enabling the button and clearing its text.
    auto clear = [] (QPushButton* button) {
        button->setEnabled(true);
        button->setText(" ");
    };

    // Map the clear function to all the QPushButtons.
    std::for_each(board_->all.begin(), board_->all.end(), clear);
}
