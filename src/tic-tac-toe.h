#ifndef TICTACTOE_H
#define TICTACTOE_H

// Qt headers
#include <QPushButton>

// STL headers
#include <vector>

struct GameBoard
{
    QPushButton* northwest;
    QPushButton* north;
    QPushButton* northeast;
    QPushButton* west;
    QPushButton* center;
    QPushButton* east;
    QPushButton* southwest;
    QPushButton* south;
    QPushButton* southeast;

    std::vector<QPushButton*> all = { northwest, north,  northeast,
                                      west,      center, east,
                                      southwest, south,  southeast };
};

class TicTacToe
{

public:

    TicTacToe(QPushButton* new_game_button, GameBoard* board);

    void ChangeTurn();
    bool CheckWinCondition();
    void NewGame();

private:

    QPushButton* new_game_button_;
    GameBoard*   board_;
    int          turn_;

};

#endif // TICTACTOE_H
