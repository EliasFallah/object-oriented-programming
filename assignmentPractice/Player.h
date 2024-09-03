#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <iomanip>
#include <string>


class Player {
    public:
        Player();
        int x;
        int y;
        int value;
        int enemyValue;
        char symbol;
        void setValues(int);  
};

// add srand(time(0)); to the constructor
Player::Player() {
    srand(time(0));
};

void Player::setValues(int value) {
    this->value = value;
    if (value == 1) {
        enemyValue = -1;
        symbol = 'X';
    } else {
        enemyValue = 1;
        symbol = 'O';
    }
}

#endif // PLAYER_H