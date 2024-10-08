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
        int distanceToSydney;
        int queueLength = 0;
        ChargingStation(int);
        int getDistanceToSydney(int cityID);
        string nameofCity(int cityID);
        double calculateQueueLength();
};

ChargingStation::ChargingStation(int cityID) {
    this->cityID = cityID;
    this->cityName = nameofCity(cityID);
    this->distanceToLastCity = distanceMap[cityID];
    this->distanceToSydney = getDistanceToSydney(cityID);
    this->numberOfChargers = chargersMap[cityID];
}

int ChargingStation::getDistanceToSydney(int cityID) {
    int cumulativeDistance = 0;
    for (int i = 0; i <=  cityID; i++) {
        cumulativeDistance += distanceMap[i];
    }
    return cumulativeDistance;
}

string ChargingStation::nameofCity(int cityID) {
    return nameMap[cityID];
}

double ChargingStation::calculateQueueLength() {
    return ((double)queueLength * 0.5) / (double)numberOfChargers;
}