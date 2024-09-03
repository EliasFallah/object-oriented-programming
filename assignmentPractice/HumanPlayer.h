#include "Player.h"

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