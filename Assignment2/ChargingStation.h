#include <iostream>
#include <string>
#include "Constant.h"

using namespace std;

class ChargingStation {
    public: 
        int cityID;
        string cityName;
        int distanceToLastCity;
        int numberOfChargers;
        ChargingStation(int);
        int distanceToSydney(int);
};

ChargingStation::ChargingStation(int cityID) {
    this->cityID = cityID;
    this->cityName = nameMap[cityID];
    this->distanceToLastCity = distanceMap[cityID];
    this->numberOfChargers = chargersMap[cityID];
    cout << cityID << " " << cityName << " " << distanceToLastCity << " " << numberOfChargers << endl; 
}

int ChargingStation::distanceToSydney(int cityID) {
    int cumulativeDistance = 0;
    for (int i = 0; i <=  cityID; i++) {
        cumulativeDistance += distanceMap[i];
    }
    return cumulativeDistance;
}