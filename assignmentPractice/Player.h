#include "TicTacToe.h"
#include <iostream>
#include <iomanip>
#include <string>


class Player {
    public:
        int row;
        int col;
        char playerSymbol;
        char playerType;
        void getMove(char player);
        bool isValidMove(int x, int y);
};

void Player::getMove(char player) {
    if (playerType == 'H') {
        

    } else {
        row = rand() %3;
        col = rand() %3;
    }
}



