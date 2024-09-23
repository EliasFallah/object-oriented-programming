//Program to demonstrate the CDAccount structure type.
#include <iostream>
#include <cmath>
#include <string>
#include "Account.h"
using namespace std;

int main( )
{
    DepositAccount depositAccount("dAccount");
    depositAccount.getBalanceAtMaturity();

    LoanAccount loanAccount("lAccount");
    loanAccount.getMonthlyPayment();

    return 0;
}