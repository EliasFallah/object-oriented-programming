#include "TicTacToe.h"

class Game {
    public:
        void play();
        void getXMove(char player, int&, int&);
        void getOMove(char player, int&, int&);
    private:
        TicTacToe board;

};

void Game::getXMove(char player, int &x, int&y){
	if (board.noOfMoves < 9){
        int row, col;
        do{
            row = rand() %3;
            col = rand() %3;
        } while (!board.isValidMove(row, col));

        x = row;
        y = col;
    }
		


}

void Game::getOMove(char player, int &x, int &y) {

	if (board.noOfMoves < 9) {
        int row, col;
        do {
            cin >> row >> col;
            cout << endl;
        } while (!board.isValidMove(row - 1, col - 1));
        x = row - 1;
        y = col - 1;
    }
    
}


void Game::play() {

	srand(time(0));
	int player = 1;

	board.displayBoard();
	int done = 0;
	while (done == 0) {
		char playerSymbol = (player == 1) ? 'X' : 'O';
		int x, y;
		if (playerSymbol == 'X') {
			getXMove(playerSymbol, x, y);
		} else {
            cout << "Enter move: ";
			getOMove(playerSymbol, x, y);
		}

		board.addMove(x, y, player);
		board.noOfMoves++;
		board.displayBoard();

		done = board.gameStatus();
		if (done == 1) {
			cout << "Player X wins!" << endl;
			
		} else if (done == -1) {
			cout << "Player O wins!" << endl;
			
		} else if (done == 2) {
			cout << "Draw game!" << endl;
			
		}

		if (player == 1)
			player = -1;
		else
			player = 1;
	}

}