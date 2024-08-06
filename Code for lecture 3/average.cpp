#include<iostream>
using namespace std;

int main() {
	int array[10] = { 43, 52, 45, 2, 54, 32, 5, 67, 86, 98 };

	double total = 0;

	cout << "The numbers were: ";
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
		total += array[i];
	}
	double mean = (double) (total / 10);
	cout << "\nThe mean was " << mean;
	return 0;
}
