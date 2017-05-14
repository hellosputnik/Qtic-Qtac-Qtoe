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

    // Once a player starts the game by placing a O or X, the new game button
    // should be enabled to start a new game.
    new_game_button_->setEnabled(true);
}

void TicTacToe::CheckWinCondition()
{
    // Disable the game board if a win condition has been met.
    auto disable = [] (QPushButton* button) { button->setEnabled(false); };

    // If the upper row is owned by a single player, then the victory condition
    // has been met.
    if (board_->northwest->text() == board_->north->text() &&
        board_->north->text() == board_->northeast->text() &&
        board_->north->text() != "") {
        std::for_each(board_->all.begin(), board_->all.end(), disable);
    }

    // If the middle row is owned by a single player, then the victory condition
    // has been met.
    if (board_->west->text() == board_->center->text() &&
        board_->center->text() == board_->east->text() &&
        board_->center->text() != "") {
        std::for_each(board_->all.begin(), board_->all.end(), disable);
    }

    // If the lower row is owned by a single player, then the victory condition
    // has been met.
    if (board_->southwest->text() == board_->south->text() &&
        board_->south->text() == board_->southeast->text() &&
        board_->south->text() != "") {
        std::for_each(board_->all.begin(), board_->all.end(), disable);
    }

    // If the left column is owned by a single player, then the victory
    // condition has been met.
    if (board_->northwest->text() == board_->west->text() &&
        board_->west->text() == board_->southwest->text() &&
        board_->west->text() != "") {
        std::for_each(board_->all.begin(), board_->all.end(), disable);
    }

    // If the middle column is owned by a single player, then the victory
    // condition has been met.
    if (board_->north->text() == board_->center->text() &&
        board_->center->text() == board_->south->text() &&
        board_->center->text() != "") {
        std::for_each(board_->all.begin(), board_->all.end(), disable);
    }

    // If the right column is owned by a single player, then the victory
    // condition has been met.
    if (board_->northeast->text() == board_->east->text() &&
        board_->east->text() == board_->southeast->text() &&
        board_->east->text() != "") {
        std::for_each(board_->all.begin(), board_->all.end(), disable);
    }

    // If a single player owns the spaces from upper left to lower right, then
    // the victory condition has been met.
    if (board_->northwest->text() == board_->center->text() &&
        board_->center->text() == board_->southeast->text() &&
        board_->center->text() != "") {
        std::for_each(board_->all.begin(), board_->all.end(), disable);
    }

    // If a single player owns the spaces from upper right to lower left, then
    // the victory condition has been met.
    if (board_->northeast->text() == board_->center->text() &&
        board_->center->text() == board_->southwest->text() &&
        board_->center->text() != "") {
        std::for_each(board_->all.begin(), board_->all.end(), disable);
    }
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

    // Clear the game board by enabling the buttons and clearing their text.
    auto clear = [] (QPushButton* button) {
        button->setEnabled(true);
        button->setText("");
    };

    // Map the clear function to all the QPushButtons on the game board.
    std::for_each(board_->all.begin(), board_->all.end(), clear);

    // Reset the turn.
    turn_ = 0;
}
