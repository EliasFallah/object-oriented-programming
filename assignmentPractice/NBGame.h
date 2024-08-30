#include "NBTicTacToe.h"
#include "Player.h"


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
        Player playerX;
        Player playerO;
        NBTicTacToe game;
};

NBGame::NBGame() {
    srand(time(0));

}

void NBGame::chosePlayers() {
    playerX.symbol = 'X';
    playerX.type = 'H';
    playerX.value = 1;
    playerO.symbol = 'O';
    playerO.type = 'C';
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
            playerX.setBoard(game.grid[game.currentBoard.x][game.currentBoard.y].board);
            playerX.getMove();
            game.play(playerX.x, playerX.y, activePlayerValue);   
        } else {
            playerO.setBoard(game.grid[game.currentBoard.x][game.currentBoard.y].board);
            playerO.getMove();
            game.play(playerO.x, playerO.y, activePlayerValue);
        }
        if (game.validMove){
            swapActivePlayer();
        }
    }
    game.grid[game.currentBoard.x][game.currentBoard.y];
}
