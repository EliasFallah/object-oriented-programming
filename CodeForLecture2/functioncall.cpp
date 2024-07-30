#include<iostream>
using namespace std;

void f(int a, double b) {
	cout << "1. int & double" << endl;
}

void f(double a, int b) {
	cout << "2. double & int" << endl;
}

void f(double a, double b) {
	cout << "3. double & double" << endl;
}


int main() {
f(4.5, 4);
f(5,5.3);
f(98.0,99.0);
return 0;
}
