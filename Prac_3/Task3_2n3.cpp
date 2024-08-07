//Functional implementation for basic Tic Tac Toe game (incomplete)

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayBoard(int board[][3]) {
	cout << "   1    2    3" << endl << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1;
		// // Check player symbols in board and prints them
		for (int j = 0; j < 3; j++) {
			char playerSymbol = ' ';
			if (board[i][j] == 1)
				playerSymbol = 'X';
			else if (board[i][j] == -1)
				playerSymbol = 'O';
			cout << setw(3) << playerSymbol;
			// prints the middle wals of the board
			if (j != 2)
				cout << " |";
		}
		cout << endl;
		if (i != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl;
	}
	cout << endl;
}

bool isValidMove(int board[][3], int x, int y) {
	bool retval = false;
	// Checks x is in correct range
	if ((x >= 0) && (x < 3)) { //Add your code here)
		// Checks y is in correct range
		if ((y >= 0) && (y < 3)){
			// Checks position has not already been filled
			if ((board[x][y] == 0)) {
				// return value method changed to allow for nested if statements and error message
				retval = true;
			}
		} 		
	} 
	// else sattement removed due to redundency 

	// else {
	// 	retval = false;
	// }
	
	if (retval == true){
		return retval;
	}else {
		// added print statement for user clarity
		cout << "Enter a valid move: ";
		return retval;
	}

}

bool getXOMove(int board[][3], int noOfMoves, int &x, int &y) {

	if (noOfMoves >= 9)
		return false;

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(board, row - 1, col - 1));
	x = row - 1;
	y = col - 1;

	return true;
}

void addMove(int board[][3], int x, int y, int player) {
	board[x][y] = player;
}

int gameStatus(int board[][3], int &noOfMoves) {
//Write your code here to check if the game has been in a win status or a draw status
//Check rows for a win

//Add your code here
	for (int i = 0; i <=3; i++) {
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])){
			return board[i][0];
		}
	}
//Check columns for a win

//Add your code here
	for (int i = 0; i <= 3; i++) {
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])){
			return board[0][i];
		}
	}

//Check diagonals for a win
	
//Add your code here
	// Checks left to right diagonal
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){
		return board[0][0];
	}
	// Checks right to left diagonal
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])){
		return board[0][2];
	}

	if (noOfMoves >= 9)
		return 2;

	return 0;
}

int main() {
	int board[3][3];
	int noOfMoves;

	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;

	int player = 1;

	displayBoard(board);
	int done = 0;
	while (done == 0) {
		char playerSymbol = (player == 1) ? 'X' : 'O';
		cout << "Player " << playerSymbol << " enter move: ";
		int x, y;

		getXOMove(board, noOfMoves, x, y);

		addMove(board, x, y, player);
		noOfMoves++;
		displayBoard(board);

		done = gameStatus(board, noOfMoves);
		if (done == 1) {
			cout << "Player X wins!" << endl;
			return 0;
		} else if (done == -1) {
			cout << "Player O wins!" << endl;
			return 0;
		} else if (done == 2) {
			cout << "Draw game!" << endl;
			return 0;
		}

		if (player == 1)
			player = -1;
		else
			player = 1;
	}

	return 0;
}