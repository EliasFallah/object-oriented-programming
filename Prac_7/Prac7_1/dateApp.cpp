#include<iostream>
#include<ctime>
#include <fstream>
#include <cstdlib>
#include<vector>

#include "Date.h"

using namespace std;

int main() {

	ifstream fin;

	//Read a date from the file
	fin.open("date_in.txt");
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(1);
	}

	char deliminator;
	int day = 0;
	int month = 0;
	int year = 0;

	fin >> day;
	fin.get(deliminator);
	fin >> month;
	fin.get(deliminator);
	fin >> year;
	fin.get(deliminator);

	Date d(day, month, year);
	cout << d << endl;

	//output the date to a file
	ofstream fout;

	fout.open("date_out.txt");
	if (fout.fail()) {
		cout << "Output file opening failed.\n";
		exit(1);
	}

	fout << d << endl;
	return 0;
}
