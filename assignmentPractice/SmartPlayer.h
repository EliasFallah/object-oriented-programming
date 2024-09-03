#include "RandomPlayer.h"
#include "NBTicTacToe.h"

class SmartPlayer : public RandomPlayer
{
public:
    SmartPlayer();
    void getMove();
    NBTicTacToe currentNBGame;
    TicTacToe activeGame;
    TicTacToe nextGame;
    void getSmartRandomMove(TicTacToe);

private:
    bool checkColumn(int, TicTacToe);
    bool checkRow(int, TicTacToe);
    bool checkDiagnol(int, TicTacToe);
    void setCurrentBoard();
    void setNextBoard(int, int);
    bool checkMove(int, TicTacToe);
    bool checkLoosingMove(TicTacToe, int, int);
};

SmartPlayer::SmartPlayer()
{
}

void SmartPlayer::setCurrentBoard()
{
    activeGame = currentNBGame.grid[currentNBGame.currentBoard.x][currentNBGame.currentBoard.y];
}

void SmartPlayer::setNextBoard(int x, int y)
{
    nextGame = currentNBGame.grid[x][y];
}

bool SmartPlayer::checkRow(int value, TicTacToe game)
{
    for (int i = 0; i < 3; i++)
    {
        if (game.board[i][0] == value && game.board[i][1] == value)
        {
            x = i;
            y = 2;
            if (game.board[x][y] == 0){
                if (!checkLoosingMove(game, x, y))
                    {
                        return true;
                    }
            }
        }
        else if (game.board[i][0] == value && game.board[i][2] == value)
        {
            x = i;
            y = 1;
            if (game.board[x][y] == 0){
                if (!checkLoosingMove(game, x, y))
                    {
                        return true;
                    }
            }
        }
        else if (game.board[i][1] == value && game.board[i][2] == value)
        {
            x = i;
            y = 0;
            if (game.board[x][y] == 0){
                if (!checkLoosingMove(game, x, y))
                    {
                        return true;
                    }
            }
        }
    }
    return false;
}

bool SmartPlayer::checkColumn(int value, TicTacToe game)
{
    for (int i = 0; i < 3; i++)
    {
        if (game.board[0][i] == value && game.board[1][i] == value)
        {
            x = 2;
            y = i;
            if (game.board[x][y] == 0){
                if (!checkLoosingMove(game, x, y))
                    {
                        return true;
                    }
            }
        }
        else if (game.board[0][i] == value && game.board[2][i] == value)
        {
            x = 1;
            y = i;
            if (game.board[x][y] == 0){
                if (!checkLoosingMove(game, x, y))
                    {
                        return true;
                    }
            }
        }
        else if (game.board[1][i] == value && game.board[2][i] == value)
        {
            x = 0;
            y = i;
            if (game.board[x][y] == 0){
                if (!checkLoosingMove(game, x, y))
                    {
                        return true;
                    }
            }
        }
    }
    return false;
}

bool SmartPlayer::checkDiagnol(int value, TicTacToe game)
{
    if (game.board[0][0] == value && game.board[1][1] == value)
    {
        x = 2;
        y = 2;
         if (game.board[x][y] == 0){
            if (!checkLoosingMove(game, x, y))
                {
                    return true;
                }
        }
    }
    else if (game.board[0][0] == value && game.board[2][2] == value)
    {
        x = 1;
        y = 1;
        if (game.board[x][y] == 0){
            if (!checkLoosingMove(game, x, y))
                {
                    return true;
                }
        }
    }
    else if (game.board[1][1] == value && game.board[2][2] == value)
    {
        x = 0;
        y = 0;
        if (game.board[x][y] == 0){
            if (!checkLoosingMove(game, x, y))
                {
                    return true;
                }
        }
    }
    else if (game.board[0][2] == value && game.board[1][1] == value)
    {
        x = 2;
        y = 0;
        if (game.board[x][y] == 0){
            if (!checkLoosingMove(game, x, y))
                {
                    return true;
                }
        }
    }
    else if (game.board[0][2] == value && game.board[2][0] == value)
    {
        x = 1;
        y = 1;
        if (game.board[x][y] == 0){
            if (!checkLoosingMove(game, x, y))
                {
                    return true;
                }
        }
    }
    else if (game.board[1][1] == value && game.board[2][0] == value)
    {
        x = 0;
        y = 2;
        if (game.board[x][y] == 0){
            if (!checkLoosingMove(game, x, y))
                {
                    return true;
                }
        }
    }
    return false;
}

// Check if the player has a winning move
bool SmartPlayer::checkMove(int value, TicTacToe game)
{
    if (checkRow(value, game))
    {
        return true;
    }
    else if (checkColumn(value, game))
    {
        return true;
    }
    else if (checkDiagnol(value, game))
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Check if the player has a losing move at the next position
bool SmartPlayer::checkLoosingMove (TicTacToe game, int storedX, int storedY) {
    setNextBoard(x, y);
    if (checkMove(enemyValue, nextGame)) {
        return true;
    } else {
        x = storedX;
        y = storedY;
        return false;
    }
}

void SmartPlayer::getSmartRandomMove(TicTacToe game) {
    do {
        getRandomMove();
    } while (checkLoosingMove(game, x, y));
}

void SmartPlayer::getMove()
{
    setCurrentBoard();
    // Check for empty winning move
    if (checkMove(value, activeGame))
    {
        return;
    }  // Check for enemy winning move in active game
    else if (checkMove(enemyValue, activeGame))
    {
        return;
    }
    else
    { // Make a random move
        getSmartRandomMove(activeGame);
    }
}