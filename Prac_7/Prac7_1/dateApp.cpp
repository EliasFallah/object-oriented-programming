#include<iostream>
#include<ctime>
#include <fstream>
#include <cstdlib>
#include<vector>
#include<cstring>

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

	//output the date to a file
	ofstream fout;
	fout.open("date_out.txt");
	if (fout.fail()) {
		cout << "Output file opening failed.\n";
		exit(1);
	}
	
	int day = 0;
	int month = 0;
	int year = 0;
	string lineTxt;
	string intText;
	while (getline(fin, lineTxt)) {
		int day = 0;
		int month = 0;
		int year = 0;
		stringstream ss(lineTxt);
		while (getline(ss, intText, '/')) {
			if (day == 0) {
				day = stoi(intText);
			}
			else if (month == 0) {
				month = stoi(intText);
			}
			else {
				year = stoi(intText);
			}
		}

		Date d(day, month, year);
		cout << d << endl;
	
		fout << d << endl;
	}
	return 0;
}
