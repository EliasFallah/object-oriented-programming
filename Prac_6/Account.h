#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Account {
    public: 
        double initialBalance;
        double interestRate;
        int term;//months until maturity
        Account(string acName);
};

Account::Account(string acName) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Account name: " << acName << endl;
    cout << "Enter the amount of initial balance: $";
    cin >> initialBalance;
    cout << "Enter interest rate percent per annual: ";
    cin >> interestRate;
    cout << "Enter the number of months: ";
    cin >> term;
    cout << endl;
}

class DepositAccount: public Account {
    public:
        DepositAccount (string acName): Account(acName) {}
        double getBalanceAtMaturity();
};

double DepositAccount::getBalanceAtMaturity () {
	   double rateFraction, interest;
	    rateFraction = interestRate/100.0;
	    interest = initialBalance*(rateFraction*(term/12.0));//simple interest
	    double balanceAtMaturity = initialBalance + interest;
        cout << "The balance of deposit at maturity is $" << balanceAtMaturity << " after " << term << " months." << endl << endl;
        return balanceAtMaturity;
}

class LoanAccount: public Account {
    public:
        LoanAccount (string acName): Account(acName) {}
        double getMonthlyPayment();
};
double LoanAccount::getMonthlyPayment() {
	    double rateFraction = interestRate/(12.0*100.0);
	    double payment = initialBalance * (rateFraction + rateFraction / (pow(1+rateFraction,term)-1.0));//simple interest
	    cout << "The monthly payment of the loan is $" << payment << " for " << term << " months." << endl << endl;
        return payment;
}