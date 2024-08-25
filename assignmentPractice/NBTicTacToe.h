#include "TicTacToe.h"
#include "Focus.h"

class NBTicTacToe {
    public:
		NBTicTacToe(int x, int y) {
			currentBoard.x = x;
			currentBoard.y = y;
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
        cout << "  - - - - -    - - - - -    - - - - -  ";
        cout << endl;

        for (int gameRow = 0; gameRow < 3; gameRow++){

            for (int gridColumn = 0; gridColumn < 3; gridColumn++){
                cout << "|";
                for (int gameColumn = 0; gameColumn < 3; gameColumn++){
					if (grid[gridRow][gridColumn].board[gameRow][gameColumn] == 1)
						playerSymbol = 'X';
					else if (grid[gridRow][gridColumn].board[gameRow][gameColumn] == -1)
						playerSymbol = 'O';
					else
						playerSymbol = ' ';
                    cout  << setw(3) << playerSymbol << "|";
                }
            }
            cout << endl;
            if (gameRow != 2){
                cout << "| -   -   - || -   -   - || -   -   - |";
                cout << endl; 
            }
        }
        cout << "  - - - - -    - - - - -    - - - - -  ";
        cout << endl;
    }

}




void NBTicTacToe::getXMove(char player, int &x, int&y){
	// if (board.noOfMoves < 9){
        int row, col;
        do{
            row = rand() %3;
            col = rand() %3;
        } while (!grid[currentBoard.x][currentBoard.y].isValidMove(row, col));

        x = row;
        y = col;
    // }
		


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

		setCurrentBoard(x, y);
	}

}