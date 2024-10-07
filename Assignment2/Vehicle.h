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
        int firstRecharge = 0;
        int secondRecharge = 0;
        Vehicle();
        int farthestCity();

};

Vehicle::Vehicle() {
};

int Vehicle::farthestCity() {
        int cumulativeDistance = 0;
    for (int i = currentCityID; i <=  destinationID; i++) {
        if ((cumulativeDistance + distanceMap[i]) > remainRange) {
            return i - 1;
        }
        cumulativeDistance += distanceMap[i];
    }
    return destinationID;
};