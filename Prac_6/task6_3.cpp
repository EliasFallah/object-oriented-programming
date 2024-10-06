#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "Constant.h"

using namespace std;

int main() {
srand(time(0));
ofstream chargingDemands("NewChargingDemands.txt");
for (int i = 1; i < 14; i++) {
    string newDemands = "[";
    newDemands += to_string(i) + ",";
    newDemands += to_string(rand() % 12) + ","; 
    newDemands += to_string(rand() % 51 + 150) + ",";
    newDemands += to_string(rand() % 201) + "]";
    cout << newDemands << endl;
    chargingDemands << newDemands << endl;
}

}