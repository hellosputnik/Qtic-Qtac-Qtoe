// Qt headers
#include <QDebug>

// STL headers
#include <algorithm>

#include "tic-tac-toe.h"

TicTacToe::TicTacToe()
{
    new_game_button_ = nullptr;
    game_board_      = nullptr;
    output_label_    = nullptr;
    turn_            = 0;
    players_[0]      = { "O", "orange"};
    players_[1]      = { "X", "purple"};
}

TicTacToe::TicTacToe(QPushButton *button, GameBoard* game_board, QLabel* label)
{
    new_game_button_ = button;
    game_board_      = game_board;
    output_label_    = label;
    turn_            = 0;
    players_[0]      = { "O", "orange" };
    players_[1]      = { "X", "purple" };
}

TicTacToe::~TicTacToe()
{
    delete game_board_;
}

void TicTacToe::ChangeTurn()
{
    // XOR between player 0 and player 1.
    turn_ ^= 1;

    // Once a player starts the game by placing a O or X, the new game button
    // should be enabled to start a new game.
    new_game_button_->setEnabled(true);

    // Set the output label to notify the user of whose turn it is.
    output_label_->setText("It is " + GetCurrentPlayer().character + " turn to go.");
}

void TicTacToe::CheckWinCondition()
{
    // Disable the game game_board if a win condition has been met.
    auto disable = [] (QPushButton* button) { button->setEnabled(false); };

    // If the upper row is owned by a single player, then the victory condition
    // has been met.
    if (game_board_->northwest->text() == game_board_->north->text() &&
        game_board_->north->text() == game_board_->northeast->text() &&
        game_board_->north->text() != "") {
        std::for_each(game_board_->all.begin(), game_board_->all.end(), disable);
        output_label_->setText(game_board_->north->text() + " wins!");
        return;
    }

    // If the middle row is owned by a single player, then the victory condition
    // has been met.
    if (game_board_->west->text() == game_board_->center->text() &&
        game_board_->center->text() == game_board_->east->text() &&
        game_board_->center->text() != "") {
        std::for_each(game_board_->all.begin(), game_board_->all.end(), disable);
        output_label_->setText(game_board_->center->text() + " wins!");
        return;
    }

    // If the lower row is owned by a single player, then the victory condition
    // has been met.
    if (game_board_->southwest->text() == game_board_->south->text() &&
        game_board_->south->text() == game_board_->southeast->text() &&
        game_board_->south->text() != "") {
        std::for_each(game_board_->all.begin(), game_board_->all.end(), disable);
        output_label_->setText(game_board_->south->text() + " wins!");
        return;
    }

    // If the left column is owned by a single player, then the victory
    // condition has been met.
    if (game_board_->northwest->text() == game_board_->west->text() &&
        game_board_->west->text() == game_board_->southwest->text() &&
        game_board_->west->text() != "") {
        std::for_each(game_board_->all.begin(), game_board_->all.end(), disable);
        output_label_->setText(game_board_->west->text() + " wins!");
        return;
    }

    // If the middle column is owned by a single player, then the victory
    // condition has been met.
    if (game_board_->north->text() == game_board_->center->text() &&
        game_board_->center->text() == game_board_->south->text() &&
        game_board_->center->text() != "") {
        std::for_each(game_board_->all.begin(), game_board_->all.end(), disable);
        output_label_->setText(game_board_->center->text() + " wins!");
        return;
    }

    // If the right column is owned by a single player, then the victory
    // condition has been met.
    if (game_board_->northeast->text() == game_board_->east->text() &&
        game_board_->east->text() == game_board_->southeast->text() &&
        game_board_->east->text() != "") {
        std::for_each(game_board_->all.begin(), game_board_->all.end(), disable);
        output_label_->setText(game_board_->east->text() + " wins!");
        return;
    }

    // If a single player owns the spaces from upper left to lower right, then
    // the victory condition has been met.
    if (game_board_->northwest->text() == game_board_->center->text() &&
        game_board_->center->text() == game_board_->southeast->text() &&
        game_board_->center->text() != "") {
        std::for_each(game_board_->all.begin(), game_board_->all.end(), disable);
        output_label_->setText(game_board_->center->text() + " wins!");
        return;
    }

    // If a single player owns the spaces from upper right to lower left, then
    // the victory condition has been met.
    if (game_board_->northeast->text() == game_board_->center->text() &&
        game_board_->center->text() == game_board_->southwest->text() &&
        game_board_->center->text() != "") {
        std::for_each(game_board_->all.begin(), game_board_->all.end(), disable);
        output_label_->setText(game_board_->center->text() + " wins!");
        return;
    }

    // Check if all spaces have been occupied.
    auto tie = [] (QPushButton* button) { return !button->isEnabled(); };

    // If all buttons have been disabled and the code reaches this section,
    // we can conclude that the game has ended in a tie.
    if (std::all_of(game_board_->all.begin(), game_board_->all.end(), tie))
        output_label_->setText("Cat's game! Draw! Tie!");
}

Player TicTacToe::GetCurrentPlayer()
{
    // Based on the turn, return the player.
    return players_[turn_];
}

void TicTacToe::NewGame()
{
    // Disable the new_game button.
    new_game_button_->setEnabled(false);

    // Clear the game game_board by enabling the buttons and clearing their text.
    auto clear = [] (QPushButton* button) {
        button->setEnabled(true);
        button->setText("");
    };

    // Map the clear function to all the QPushButtons on the game game_board.
    std::for_each(game_board_->all.begin(), game_board_->all.end(), clear);

    // Reset the turn.
    turn_ = 0;

    // Set the output label to notify the user of the new game.
    output_label_->setText("A new game has been started.");
}
