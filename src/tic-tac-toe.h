#ifndef TICTACTOE_H
#define TICTACTOE_H

// Qt headers
#include <QPushButton>

// STL headers
#include <vector>

struct GameBoard
{
    QPushButton* northwest; QPushButton* north;  QPushButton* northeast;
    QPushButton* west;      QPushButton* center; QPushButton* east;
    QPushButton* southwest; QPushButton* south;  QPushButton* southeast;

    std::vector<QPushButton*> all;

    void Initialize()
    {
        all = { northwest, north,  northeast,
                west,      center, east,
                southwest, south,  southeast };
    }
};

class TicTacToe
{

public:

    // Tic-Tac-Toe constructors and destructors
    TicTacToe();
    TicTacToe(QPushButton* new_game_button, GameBoard* board);
    ~TicTacToe();

    // Tic-Tac-Toe methods
    void  ChangeTurn();
    void  CheckWinCondition();
    QChar GetCurrentPlayer();
    void  NewGame();

private:

    // Tic-Tac-Toe data members
    QPushButton* new_game_button_;
    GameBoard*   board_;
    int          turn_;
    QChar        players_[2];

};

#endif // TICTACTOE_H
