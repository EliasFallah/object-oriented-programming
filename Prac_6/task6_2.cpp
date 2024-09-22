#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "Constant.h"

using namespace std;

int main() {
    
    string lineTxt;
    string intText;
    ifstream chargingDemands("ChargingDemands.txt");
    cout << "Vehicle Id" << setw(20) << "Destination Id" << setw(20) 
        << "Capacity Range" << setw(20) << "Remaining Range" << endl;
    while (getline(chargingDemands, lineTxt)) {
        int vehicleID;
        int destinationID;
        int capacityRange;
        int remainRange;
        lineTxt.erase(0, 1);    
        lineTxt.pop_back();
        stringstream ss(lineTxt);
        int i = 0;
        while (getline(ss, intText, ',')) {
            switch(i){
                case 0:
                    vehicleID = stoi(intText);
                    break;
                case 1:
                    destinationID = stoi(intText);
                    break;
                case 2:
                    capacityRange = stoi(intText);
                    break;
                case 3:
                    remainRange = stoi(intText);
                    break;
            }
            i++;
        }
        cout << vehicleID << setw(20) << nameMap[destinationID] << setw(20) << capacityRange 
        << setw(20) << remainRange << endl;

    }

    chargingDemands.close();
}