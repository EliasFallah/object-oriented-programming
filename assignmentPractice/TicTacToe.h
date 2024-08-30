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
	

public:
int board[BOARDSIZE][BOARDSIZE];
	TicTacToe();
	bool isValidMove(int, int);
	void addMove(int, int, int);
	int boardStatus();
	int play();

	int noOfMoves;
};

TicTacToe::TicTacToe() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;
	noOfMoves = 0;
}

bool TicTacToe::isValidMove(int x, int y) {
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
	cout << "Invalid move, please try again" << endl;
	return false;	
	
}

void TicTacToe::addMove(int x, int y, int player) {
	board[x][y] = player;
	noOfMoves++;						   
}

int TicTacToe::boardStatus() {
//Check rows for a win
	for (int i = 0; i <=3; i++) {
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])){
			return board[i][0];
		}
	}

//Check columns for a win
	for (int i = 0; i <= 3; i++) {
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])){
			return board[0][i];
		}
	}

//Check diagonals for a win
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

#endif /* TICTACTOE_H_ */
