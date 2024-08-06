#include <string>
#include <iostream>
using namespace std;

double dailySales(){
    double userInput;
    cout << "Please enter the amount of product you sold today: ";
    cin >> userInput;
    return userInput;
}

float calculateComission(double sales){
    float comission;
    if(sales < 1000){
        comission = sales * 0.03;
    } else if(sales < 3000){
        comission = sales * 0.035;
    } else {
        comission = sales * 0.045;
    }
    return comission;
}



int main(){
    double sales = dailySales();
    float comission = calculateComission(sales);
    cout << comission << endl;
    return 0;
}

