#include "NBTicTacToe.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "SmartPlayer.h"
#include "RandomPlayer.h"



class NBGame
{
private:
    /* data */
public:
    NBGame();
    void chosePlayers();
    void start();
    void swapActivePlayer();
    char activePlayerValue = 1;
    private:
        HumanPlayer playerX;
        SmartPlayer playerO;
        NBTicTacToe game;
};

NBGame::NBGame() {
    srand(time(0));
}

void NBGame::chosePlayers() {
    playerO.symbol = 'O';
    playerO.value = -1;
}

void NBGame::swapActivePlayer() {
    if (activePlayerValue == playerX.value) {
        activePlayerValue = playerO.value;
    } else {
        activePlayerValue = playerX.value;
    }
}


void NBGame::start() {
    chosePlayers();
    game.displayBoard();
    while (!game.gameComplete) {
        if(activePlayerValue == playerX.value) {
            playerX.getMove();
            game.play(playerX.x, playerX.y, activePlayerValue);   
        } else {
            playerO.game = game;
            playerO.getMove();
            game.play(playerO.x, playerO.y, activePlayerValue);
        }
        if (game.validMove){
            swapActivePlayer();
        }
    }
}
