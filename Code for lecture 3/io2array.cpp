#include<iostream>
#include<iomanip>

using namespace std;

const int ROWS=2;
const int COLS=3;

int main() {

	int table[ROWS][COLS];

	for (int i = 0; i < ROWS; i ++)
		for (int j = 0; j < COLS; j++)   {
			cout << "Enter the next value: ";
			cin  >> table[i][j];
		}


	for (int i = 0; i < ROWS; i ++)  {
		for (int j = 0; j < COLS; j++)
			cout << setw(3) << table[i][j];

		cout << endl;
	 }

	return 0;
}
