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
        int board[3][3];
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

class RandomPlayer : public Player {
    public:
        RandomPlayer();
        void getMove();
    private:
};
RandomPlayer::RandomPlayer() {
}

void RandomPlayer::getMove() {
    int row, col;
    row = rand() %3;
    col = rand() %3;
    x = row;
    y = col;
}

class HumanPlayer : public Player {
    public:
        HumanPlayer();
        void getMove();
    private:
};

// Human player is always X
HumanPlayer::HumanPlayer() {
    symbol = 'X';
    value = 1;
}

void HumanPlayer::getMove() {
    int row, col;
    cout << "Enter move for Player " << symbol << ": ";
    cin >> row >> col;
    cout << endl;
    x = row - 1;
    y = col - 1;
}

class SmartPlayer : public Player {
    public:
        SmartPlayer();
        void getMove();
    private:
        bool winningMove();
        bool checkLosingMove();
        bool randomMove();
        bool checkColumn(int);
        bool checkRow(int);
        bool checkDiagnol(int);
};

SmartPlayer::SmartPlayer() {
}

bool SmartPlayer::checkRow(int value) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == value && board[i][1] == value) {
            x = i;
            y = 2;
            return true;
        } else if ( board[i][0] == value && board[i][2] == value) {
            x = i;
            y = 1;
            return true;
        }else if (board[i][1] == value && board[i][2] == value) {
            x = i;
            y = 0;
            return true;
        }
    }
    return false;
}

bool SmartPlayer::checkColumn(int value) {
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == value && board[1][i] == value) {
            x = 2;
            y = i;
            return true;
        } else if (board[0][i] == value && board[2][i] == value) {
            x = 1;
            y = i;
            return true;
        } else if (board[1][i] == value && board[2][i] == value) {
            x = 0;
            y = i;
            return true;
        }
    }
    return false;
}

bool SmartPlayer::checkDiagnol(int value) {
    if (board[0][0] == value && board[1][1] == value) {
        x = 2;
        y = 2;
        return true;
    } else if (board[0][0] == value && board[2][2] == value) {
        x = 1;
        y = 1;
        return true;
    } else if (board[1][1] == value && board[2][2] == value) {
        x = 0;
        y = 0;
        return true;
    } else if (board[0][2] == value && board[1][1] == value) {
        x = 2;
        y = 0;
        return true;
    } else if (board[0][2] == value && board[2][0] == value) {
        x = 1;
        y = 1;
        return true;
    } else if (board[1][1] == value && board[2][0] == value) {
        x = 0;
        y = 2;
        return true;
    }
    return false;
}




bool SmartPlayer::winningMove() {
    // Check rows for a win
    if (checkRow(value)) {
        return true;
    } else if (checkColumn(value)) {
        return true;
    } else if (checkDiagnol(value)) {
        return true;
    } else {
        return false;
    }
}

bool SmartPlayer::checkLosingMove() {
    int otherValue;
    (value == 1) ? otherValue = -1 : otherValue = 1;
    if (checkRow(otherValue)) {
        return true;
    } else if (checkColumn(otherValue)) {
        return true;
    } else if (checkDiagnol(otherValue)) {
        return true;
    } else {
        return false;
    }
}

bool SmartPlayer::randomMove() {
    int row, col;
    row = rand() %3;
    col = rand() %3;
    x = row;
    y = col;
    return false;
}

void SmartPlayer::getMove() {
    // Check for empty winning move
    if (winningMove() && board[x][y] == 0) {
        return;
    // Check for empty losing move
    } else if (checkLosingMove() && board[x][y] == 0) {
        return;
    } else { // Make a random move
        randomMove();
    }
}