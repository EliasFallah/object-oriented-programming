#include "NBTicTacToe.h"
#include "Player.h"


class NBGame
{
private:
    /* data */
public:
    
    char activePlayerSymbol = playerX.playerSymbol;
    NBGame();
    void chosePlayers();
    void start();
    void swapActivePlayer();
    private:
        Player playerX;
        Player playerO;
        NBTicTacToe game;
};

NBGame::NBGame() {
    srand(time(0));
}

void NBGame::chosePlayers() {
    playerX.playerSymbol = 'X';
    playerX.playerType = 'H';
    playerO.playerSymbol = 'O';
    playerO.playerType = 'C';
}

void NBGame::swapActivePlayer() {
    if (activePlayerSymbol == playerX.playerSymbol) {
        activePlayerSymbol = playerO.playerSymbol;
    } else {
        activePlayerSymbol = playerX.playerSymbol;
    }
}


void NBGame::start() {
    chosePlayers();
    game.initializeGame();
    while (!game.gameComplete) {
        if(activePlayerSymbol == playerX.playerSymbol) {
            playerX.getMove(activePlayerSymbol);
            game.play(playerX.row, playerX.col, activePlayerSymbol);   
        } else {
            playerO.getMove(activePlayerSymbol);
            game.play(playerO.row, playerO.col, activePlayerSymbol);
        }
        swapActivePlayer();
    }
    
}
