#include "TicTacToe.h"
#include "Focus.h"

class NBTicTacToe {
    public:
		NBTicTacToe(int x, int y) {
			srand(time(0));
			currentBoard.x = rand() % 3;
			currentBoard.y = rand() % 3;
		};
        void play();
        void getXMove(char player, int&, int&);
        void getOMove(char player, int&, int&);
		void displayBoard();
		void setCurrentBoard(int, int);
    private:
        TicTacToe grid[3][3];
		Coordinate currentBoard;

};


void NBTicTacToe::displayBoard() {
    char playerSymbol = ' ';
    for (int gridRow = 0; gridRow < 3; gridRow++){
		for (int k = 0; k < 3; k++) {
			if (k == currentBoard.y && gridRow == currentBoard.x) {
				cout << "  * * * * * ";
			} else {
		        cout << "  - - - - -  ";
			}
		}
        cout << endl;

        for (int gameRow = 0; gameRow < 3; gameRow++){

            for (int gridColumn = 0; gridColumn < 3; gridColumn++){
				if (gridColumn == currentBoard.y && gridRow == currentBoard.x) {
					cout << "*";
				} else{
					cout << "|";
				}
                for (int gameColumn = 0; gameColumn < 3; gameColumn++){
					if (grid[gridRow][gridColumn].board[gameRow][gameColumn] == 1)
						playerSymbol = 'X';
					else if (grid[gridRow][gridColumn].board[gameRow][gameColumn] == -1)
						playerSymbol = 'O';
					else
						playerSymbol = ' ';
					if (gameColumn == 2){
						cout << setw(3) << playerSymbol;
						if (gridColumn == currentBoard.y && gridRow == currentBoard.x) {
							cout << "*";
						} else {
							cout << "|";
						}
					} else {
						cout << setw(3) << playerSymbol << "|";
					}

                    
					
                }
            }
            cout << endl;
            if (gameRow != 2){
				for (int k = 0; k < 3; k++) {
					if (k == currentBoard.y && gridRow == currentBoard.x) {
						cout << "* -   -   - *";
					} else {
                		cout << "| -   -   - |";
					}
				}
                cout << endl; 
            }
        }
		// print bottom of game
		for (int k = 0; k < 3; k++) {
			// print star if current board
            if (k == currentBoard.y && gridRow == currentBoard.x) {
				cout << "  * * * * * ";
			} else { // print horizontal line
		        cout << "  - - - - -  ";
			}
		}
        cout << endl;
    }
cout << endl << endl << endl;
}




void NBTicTacToe::getXMove(char player, int &x, int&y){
	// if (board.noOfMoves < 9){
        // int row, col;
        // do{
        //     row = rand() %3;
        //     col = rand() %3;
        // } while (!grid[currentBoard.x][currentBoard.y].isValidMove(row, col));

        // x = row;
        // y = col;
    // }
		        int row, col;
        do {
            cin >> row >> col;
            cout << endl;
        } while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1));
        x = row - 1;
        y = col - 1;


}

void NBTicTacToe::getOMove(char player, int &x, int &y) {
	// if (board.noOfMoves < 9) {
        int row, col;
        do {
            cin >> row >> col;
            cout << endl;
        } while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1));
        x = row - 1;
        y = col - 1;
    // }
    
}

void NBTicTacToe::setCurrentBoard(int x, int y) {
	currentBoard.x = x;
	currentBoard.y = y;
}

void NBTicTacToe::play() {
	srand(time(0));
	displayBoard();
	int player = 1;
	int done = 0;
	while (done == 0) {
		char playerSymbol = (player == 1) ? 'X' : 'O';
		
		int x, y;
		if (playerSymbol == 'X') {
			cout << "Enter move: ";
			getXMove(playerSymbol, x, y);
		} else {
            cout << "Enter move: ";
			getOMove(playerSymbol, x, y);
		}

		grid[currentBoard.x][currentBoard.y].addMove(x, y, player);
		grid[currentBoard.x][currentBoard.y].noOfMoves++;
		
		displayBoard();

		done = grid[currentBoard.x][currentBoard.y].gameStatus();
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
		if (done == 0) {
			setCurrentBoard(x, y);
			displayBoard();
		}
	}

}