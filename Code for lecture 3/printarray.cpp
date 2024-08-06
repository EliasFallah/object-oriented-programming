#include<iostream>

using namespace std;

void printArray(int a[], int length) {
	for(int i=0;i<length;i++)
		cout << a[i] << endl;
}

void printArray(double a[], int length) {
	for(int i=0;i<length;i++)
		cout << a[i] << endl;
}

int main() {
	int a[] = {1,2,3,4,5};
	printArray(a, 5);
        cout << endl;
	double b[] = {0.1,0.2,0.3,0.4,0.5, 0.6};
	printArray(b, 6);
	return 0;
}