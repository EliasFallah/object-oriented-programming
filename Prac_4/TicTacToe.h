/*
 * TicTacToe.h
 *
 *  Created on: 5 Aug 2023
 *      Author: 2002345
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

const int BOARDSIZE = 3;

class TicTacToe {
private:
	int board[BOARDSIZE][BOARDSIZE];
	int noOfMoves;
public:
	TicTacToe();
	bool isValidMove(int, int);
	bool getOMove(int&, int&);
	bool getXMove(int&, int&);
	void addMove(int, int, int);
	int gameStatus();
	int play();
	void displayBoard();
};

TicTacToe::TicTacToe() {//How to call this function?
	for (int row = 0; row < 3; row++)  // (TicTacToe object name).TicTacToe()
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}

void TicTacToe::displayBoard() {//Where to get the board data?
	cout << "   1    2    3" << endl << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1;
		for (int j = 0; j < 3; j++) {
			char playerSymbol = ' ';
			if (board[i][j] == 1)
				playerSymbol = 'X';
			else if (board[i][j] == -1)
				playerSymbol = 'O';
			cout << setw(3) << playerSymbol;
			if (j != 2)
				cout << " |";
		}
		cout << endl;
		if (i != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl;
	}
	cout << endl;
}

bool TicTacToe::isValidMove(int x, int y) {//Add your code to complete the program
	
	// Checks x is in correct range
	if ((x >= 0) && (x < 3)) { //Add your code here)
		// Checks y is in correct range
		if ((y >= 0) && (y < 3)){
			// Checks position has not already been filled
			if ((board[x][y] == 0)) {
				// return value method changed to allow for nested if statements and error message
				return true;
			}
		} 		
	} 
	return false;
		
}

bool TicTacToe::getOMove(int &x, int &y) {//What does & mean?

	if (noOfMoves >= 9)
		return false;

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;

	return true;
}

bool TicTacToe::getXMove(int &x, int&y){
	if (noOfMoves >= 9)
		return false;

	int row, col;
	do{
		row = rand() %3;
		col = rand() %3;
	} while (!isValidMove(row, col));

	x = row;
	y = col;

	return true;
}



void TicTacToe::addMove(int x, int y, int player) {//What is this function for?
	board[x][y] = player;						   // Adds the value of the current player to the entered board position. 
}

int TicTacToe::gameStatus() {//Add your code to complete the program
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

int TicTacToe::play() {//What is the counterpart of this function in the original code
						// int main()
	// seed a new set of random numbers at the start of hte game
	srand(time(0));
	int player = 1;

	displayBoard();
	int done = 0;
	while (done == 0) {
		char playerSymbol = (player == 1) ? 'X' : 'O';
		cout << "Player " << playerSymbol << " enter move: ";
		int x, y;
		if (playerSymbol == 'X') {
			getXMove(x, y);
		} else {
			getOMove(x, y);
		}

		addMove(x, y, player);
		noOfMoves++;
		displayBoard();

		done = gameStatus();
		if (done == 1) {
			cout << "Player X wins!" << endl;
			return 1;
		} else if (done == -1) {
			cout << "Player O wins!" << endl;
			return -1;
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



#endif /* TICTACTOE_H_ */
