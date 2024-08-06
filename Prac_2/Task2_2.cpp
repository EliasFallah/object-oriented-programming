#include <iostream>
#include <string>
using namespace std;

// Quotient does not return floats
void calculate(int numerator, int denominator, double& quotient, int& remainder) {
    quotient = numerator / denominator;
    remainder = numerator % denominator;
}

int main() {
    int numerator = 143;
    double denominator = 2;
    double quotient = 0;
    int remainder = 0;

    calculate(numerator, denominator, quotient, remainder);

    cout << "Quotient = " << quotient << endl;
    cout << "Remainder = " << remainder << endl;
}