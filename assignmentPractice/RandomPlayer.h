#include "Player.h"

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