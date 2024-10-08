#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "Constant.h"

using namespace std;

class DemandGenerator {
    public: 
        DemandGenerator();
    private:        
        string fileName;
        int numDemands;
        int vehicleID;
        int destinationID;
        int capacityRange;
        int remainRange;
        void newDemand(int);
};

DemandGenerator::DemandGenerator() {
    srand(time(0));
    this->fileName = "NewChargingDemands.txt";
    this->numDemands = rand() % 51 + 350;

    ofstream chargingDemands(fileName);
    for (int i = 200; i < numDemands; i++) {
        newDemand(i);
        string newDemands = to_string(vehicleID) + ",";
        newDemands += to_string(destinationID) + ","; 
        newDemands += to_string(capacityRange) + ",";
        newDemands += to_string(remainRange);
        chargingDemands << newDemands << endl;
    }
    cout << "New Charging Demands Generated" << endl << endl;
}

void DemandGenerator::newDemand(int num) {
    vehicleID = num;
    destinationID = rand() % (NUM_CITIES-1) + 1;
    capacityRange = rand() % 201 + 350;
    remainRange = rand() % (capacityRange - MIN_REMAIN_RANGE) + MIN_REMAIN_RANGE;
}
