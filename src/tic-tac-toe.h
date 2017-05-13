#ifndef TICTACTOE_H
#define TICTACTOE_H

// Qt headers
#include <QPushButton>

// STL headers
#include <vector>

// TODO: Determine if smart pointers are applicable here.
template <typename T>
struct GameBoard
{
    T* northwest;
    T* north;
    T* northeast;
    T* west;
    T* center;
    T* east;
    T* southwest;
    T* south;
    T* southeast;

    std::vector<T*> all = { northwest, north,  northeast,
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
