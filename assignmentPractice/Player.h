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
        int board[3][3];
        void getMove();
        void testPrintBoard();
        void setBoard(int [3][3]);  
};

// add srand(time(0)); to the constructor
Player::Player() {
    srand(time(0));
}

void Player::setBoard(int gameBoard[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = gameBoard[i][j];
        }
    }
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

void Player::testPrintBoard() {
    cout << "Board accessable in testPrintBoard" << endl;
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}



