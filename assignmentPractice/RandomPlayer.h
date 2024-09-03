#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "Player.h"

class RandomPlayer : public Player {
    public:
        RandomPlayer();
        void getRandomMove();
    private:
};

RandomPlayer::RandomPlayer() {
}

void RandomPlayer::getRandomMove() {
    int row, col;
    row = rand() %3;
    col = rand() %3;
    x = row;
    y = col;
}

#endif // RANDOMPLAYER_H