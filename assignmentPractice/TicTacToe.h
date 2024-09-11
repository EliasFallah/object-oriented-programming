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
	bool boardStatus(int);
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
	if (((x >= 0) && (x < 3)) && ((y >= 0) && (y < 3)) && board[x][y] == 0) { //Add your code here)
		return true;
	}else {
		return false;
	}		 
}

void TicTacToe::addMove(int x, int y, int player) {
	board[x][y] = player;
	noOfMoves++;						   
}

bool TicTacToe::boardStatus(int pValue) {
	//Check rows for a win
	for (int i = 0; i <=3; i++) {
		// Check rows for a win
		if ((board[i][0] == pValue) && (board[i][1] == pValue) && (board[i][2] == pValue)){
			return true;
		} // Check columns for a win
		if ((board[0][i] == pValue) && (board[1][i] == pValue) && (board[2][i] == pValue)){
			return true;
		}
	}
	//Check diagonals for a win
	// Checks left to right diagonal
	if ((board[0][0] == pValue) && (board[1][1] == pValue) && (board[2][2] == pValue)){
		return true;
	}else if ((board[0][2] == pValue) && (board[1][1] == pValue) && (board[2][0] == pValue)){
	// Checks right to left diagonal
		return true;
	}
	return false;
}

#endif /* TICTACTOE_H_ */
