#include <iostream>
#include <string>
#include "Constant.h"

using namespace std;

class Vehicle {
    public: 
        int vehicleID;
        int currentCityID = 0;
        int destinationID;
        int capacityRange;
        int remainRange;
        Vehicle(int);
        int farthestCity();
};

Vehicle::Vehicle(int vehicleID) {
    this->vehicleID = vehicleID;
    this->destinationID = rand() % NUM_CITIES;
    this->capacityRange = rand() % 201 + 350;
    this->remainRange = rand() % (capacityRange - MIN_REMAIN_RANGE) + MIN_REMAIN_RANGE;
    cout << vehicleID << " " << currentCityID << " " << destinationID << " " << capacityRange << " " << remainRange << endl;
}

int Vehicle::farthestCity() {
        int cumulativeDistance = 0;
    for (int i = currentCityID; i <=  destinationID; i++) {
        if ((cumulativeDistance + distanceMap[i]) > remainRange) {
            return i - 1;
        }
        cumulativeDistance += distanceMap[i];
    }
    return destinationID;
}