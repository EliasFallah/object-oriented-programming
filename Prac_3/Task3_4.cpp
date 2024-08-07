/*
 * Task3_2.cpp
 *
 *  Created on: 3 Aug 2023
 *      Author: 2002345
 */

#include<iostream>

using namespace std;

void printGrid(int grid[][9]) {
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) {
			cout << "\n";
		}
		for (int j = 0; j < 9; j++) {
			char symbol;
			// prints a blank space after every 3rd symbol
			if (j % 3 == 0){
				cout << "   ";
			}
			// Prints symbol based on randomly generated number in array
			if (grid[i][j] == 1)
				symbol = 'X';
			else if (grid[i][j] == -1)
				symbol = 'O';
			else
				symbol = '_';

			cout << symbol;
			
		}
		cout << endl;
	}
}

int main() {

	int grid[9][9];

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			grid[i][j] = rand() % 3 - 1;

	printGrid(grid);

	return 0;
}
