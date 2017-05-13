#include "tic-tac-toe.h"

TicTacToe::TicTacToe(QPushButton *new_game_button, GameBoard *board)
{
    this->new_game_button_ = new_game_button;
    this->board_           = board;
    this->turn_            = 0;
}

void TicTacToe::ChangeTurn()
{
    this->turn_ ^= 1;
}

bool TicTacToe::CheckWinCondition()
{
    // Check horizontally.
    // Check vertically.
    // Check diagonally.
}

void TicTacToe::NewGame()
{
    // Disable the new_game button.
    // Clear the game board.
    // Enable the spaces to be clicked.
}

