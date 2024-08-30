#include "TicTacToe.h"
#include "Focus.h"

class NBTicTacToe {
    public:
		NBTicTacToe();
        bool play(int, int, int);
		void displayBoard();
		void setCurrentBoard(int, int);
		bool gameStatus();
		bool gameComplete = false;
		bool validMove;
    private:
        TicTacToe grid[3][3];
		Coordinate currentBoard;
		bool drawGame;
		
};
NBTicTacToe::NBTicTacToe() {
	srand(time(0));
	currentBoard.x = rand() % 3;
	currentBoard.y = rand() % 3;
}

// Display the board
// Check if the game is a draw
void NBTicTacToe::displayBoard() {
	// Set the draw game to true if there are no empty spaces
	drawGame = true;
	// Distance from previous board
	cout << endl << endl << endl;
    char playerSymbol = ' ';
	// print the grid
    for (int gridRow = 0; gridRow < 3; gridRow++){
		// print the top of the game
		for (int k = 0; k < 3; k++) {
			// print star if current board
			if (k == currentBoard.y && gridRow == currentBoard.x) {
				cout << "  * * * * * ";
			} else { 
		        cout << "  - - - - -  ";
			}
		}
        cout << endl;
		// print the game
		// print the rows of the game
        for (int gameRow = 0; gameRow < 3; gameRow++){
			// print the columns of the grid
            for (int gridColumn = 0; gridColumn < 3; gridColumn++){
				// print star if current board
				if (gridColumn == currentBoard.y && gridRow == currentBoard.x) {
					cout << "*";
				} else{
					cout << "|";
				} // print the columns of the game
                for (int gameColumn = 0; gameColumn < 3; gameColumn++){			
					// print the player symbol
					if (grid[gridRow][gridColumn].board[gameRow][gameColumn] == 1)
						playerSymbol = 'X';
					else if (grid[gridRow][gridColumn].board[gameRow][gameColumn] == -1)
						playerSymbol = 'O';
					else {
						playerSymbol = ' ';
					// Set draw game to false if there is an empty space
						drawGame = false;
					}
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
cout << endl;
}


// Set the current board to the last move
void NBTicTacToe::setCurrentBoard(int x, int y) {
	if (grid[x][y].noOfMoves == 9) {
		currentBoard.x = rand() % 3;
		currentBoard.y = rand() % 3;
	} else {
		currentBoard.x = x;
		currentBoard.y = y;
	}
}

bool NBTicTacToe::gameStatus(){
	bool retval = true;
	// If the game is over print the winning board
	if (grid[currentBoard.x][currentBoard.y].boardStatus() == 1) {
		displayBoard();
		cout << "Player X wins!" << endl;
	} else if (grid[currentBoard.x][currentBoard.y].boardStatus() == -1) {
		displayBoard();
		cout << "Player O wins!" << endl;
		// Check if drawGame has been set to false in the draw board function
	} else if (drawGame == true) {
		displayBoard();
		cout << "Draw game!" << endl;
	} else { // If the game is not over set the return value to false
		retval = false;
	}
	return retval;
}

bool NBTicTacToe::play(int x, int y, int player) {
	validMove = grid[currentBoard.x][currentBoard.y].isValidMove(x, y);
	if (validMove){
		grid[currentBoard.x][currentBoard.y].addMove(x, y, player);
		cout << "Player " << player << "'s move (" << x + 1 << ", " << y + 1 << ")" << endl;
		gameComplete = gameStatus();
		// Set the current board to the last move
		if (!gameComplete){
			setCurrentBoard(x, y);
			displayBoard();
		} 
	} 
}