#include <iostream>
#include <cmath>

using namespace std;

double monthlyPayment(double principal, int years, double rate) {
    int months = years * 12;
    double i = rate/(12.0*100.0);
    
    double payment = principal * (i + i/(pow(1+i, months)-1));
    
    return payment;
    
}

int main(int argc, const char * argv[])
{

    double principal;
    int years;
    double rate;
    
    cout << "Input the principal, years and rate" << endl;
    cin >> principal >> years >> rate;
    
    std::cout << "Monthly payment is " << monthlyPayment(principal, years, rate);
    
    
    return 0;
}

