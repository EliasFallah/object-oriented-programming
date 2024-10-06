#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "Constant.h"

using namespace std;

class DemandGenerator {
    public: 
        string fileName;
        int numDemands;
        DemandGenerator();
};

DemandGenerator::DemandGenerator() {
    srand(time(0));
    this->fileName = "NewChargingDemands.txt";
    this->numDemands = rand() % 51 + 150;

    ofstream chargingDemands(fileName);
    for (int i = 1; i < numDemands; i++) {
        string newDemands = to_string(i) + ",";
        newDemands += to_string(rand() % NUM_CITIES) + ","; 
        int capacityRange = rand() % 201 + 350;
        newDemands += to_string(capacityRange) + ",";
        newDemands += to_string(rand() % (capacityRange - MIN_REMAIN_RANGE) + MIN_REMAIN_RANGE);
        cout << newDemands << endl;
        chargingDemands << newDemands << endl;
    }
}
