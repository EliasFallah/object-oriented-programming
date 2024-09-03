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
        char symbol;;  
};

// add srand(time(0)); to the constructor
Player::Player() {
    srand(time(0));
};

#endif // PLAYER_H