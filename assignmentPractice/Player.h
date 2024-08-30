#include "TicTacToe.h"
#include <iostream>
#include <iomanip>
#include <string>


class Player {
    public:
        Player();
        int x;
        int y;
        int value;
        char symbol;
        char type;
        void getMove();

};

// add srand(time(0)); to the constructor
Player::Player() {
    srand(time(0));
}

void Player::getMove() {
    int row, col;
    if (type == 'H') {
        cout << "Enter move for Player X: ";
        cin >> row >> col;
        cout << endl;
        x = row - 1;
        y = col - 1;
    } else if (type == 'C') {
        row = rand() %3;
        col = rand() %3;
        x = row;
        y = col;
    }
}



