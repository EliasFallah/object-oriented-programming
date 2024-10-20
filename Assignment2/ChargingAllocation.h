#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
#include "Vehicle.h"
#include "ChargingStation.h"


using namespace std;

class ChargingAllocation {
    public:
        ChargingAllocation();
        void displayVehicles();
        void displayChargers();
        void allocateCharging();
        void printCharging();
    private:
        vector<Vehicle> vehicles;
        vector<Vehicle>::iterator it;
        vector<ChargingStation> chargers;
        void generateVehicles();
        void generateChargers();
        void displayQueue();
};

ChargingAllocation::ChargingAllocation() {
    generateVehicles();
    generateChargers();
    }

void ChargingAllocation::generateVehicles() {
    string lineText;
    string intText;
    ifstream chargingDemands("NewChargingDemands.txt");
    while (getline(chargingDemands, lineText)) {
        Vehicle v;
        stringstream ss(lineText);
        int i = 0;
        while (getline(ss, intText, ',')) {
            switch (i) {
                case 0:
                    v.vehicleID = stoi(intText);
                    break;
                case 1:
                    v.destinationID = stoi(intText);
                    break;
                case 2:
                    v.capacityRange = stoi(intText);
                    break;
                case 3:
                    v.remainRange = stoi(intText);
                    break;
            }
            i++;
        }
        vehicles.push_back(v);
    }
}

void ChargingAllocation::displayVehicles() {
    cout << "Vehicle Information - " << endl;
    cout << "Vehicle ID" << setw(10) << "Origin" << setw(20) << "Destination ID" << setw(20);
    cout << "Capacity Range" << setw(20) << "Remaining Range" << endl;
    for (Vehicle v : vehicles) {
        cout << setw(5) << v.vehicleID << setw(15) << nameMap[v.currentCityID] << setw(19) << nameMap[v.destinationID] << setw(15);
        cout << v.capacityRange << setw(20) << v.remainRange << endl;
    }
    cout << endl << endl;
}

void ChargingAllocation::generateChargers() {
    for(int i = 0; i < NUM_CITIES; i++) {
        ChargingStation cs(i);
        chargers.push_back(cs);
    }
}

void ChargingAllocation::displayChargers() {
    cout << "Charging Station Information - " << endl;
    cout << "Location ID" << setw(20) << "Location Name" << setw(25);
    cout << "Distance to Sydney" << setw(20) << "no of Chargers" << endl;
    for (ChargingStation cs : chargers) {
        cout << setw(5) << cs.cityID << setw(25) << cs.nameofCity(cs.cityID) << setw(20) << cs.distanceToSydney << setw(20) << cs.numberOfChargers << endl;
    }
    cout << endl << endl;
}

void ChargingAllocation::allocateCharging() {
    for (it = vehicles.begin(); it != vehicles.end(); ++it) {
        if (it->destinationID > it->farthestCity()) {
            it->firstRecharge = it->farthestCity();
            chargers[it->firstRecharge].queueLength++;
            it->currentCityID = it->firstRecharge;
            it->remainRange = it->capacityRange;
            if (it->destinationID > it->farthestCity()) {
                it->secondRecharge = it->farthestCity();
                chargers[it->secondRecharge].queueLength++;
                it->currentCityID = it->secondRecharge;
                it->remainRange = it->capacityRange;
            }
        } else {
            vehicles.erase(it);
            it--;
        }
    }
}

void ChargingAllocation::printCharging() {
    cout << "Initial Charging Allocation - " << endl;
    cout << "Vehicle ID" << setw(20) << "Destination" << setw(20) << "Capacity Range" << setw(20);
    cout << "Remaining Range" << setw(20) << "First Recharge" << setw(20) << "Second Recharge" << endl;
    for (Vehicle v : vehicles) {
                cout << setw(5) << v.vehicleID << setw(24) << nameMap[v.destinationID] << setw(15);
        cout << v.capacityRange << setw(20) << v.remainRange << setw(20);
        // print recharge locations
        if (v.firstRecharge == 0) {
            cout << "----";
        } else {
            cout << chargers[v.firstRecharge].cityName;
        }
        if (v.secondRecharge == 0) {
            cout << setw(20) << "----";
        } else {
            cout << setw(20) << chargers[v.secondRecharge].cityName;
        }
        cout << endl;
    }
    cout << endl << endl;
    displayQueue();
}

void ChargingAllocation::displayQueue() {
    cout << "Queue Length - " << endl;
    cout << "Location ID" << setw(20) << "Location Name" << setw(25) << "Distance to Sydney" << setw(20);
    cout << "no of Chargers" << setw(20) << "Queue Length" << setw(20) << "Waiting hours" << endl;
    for (ChargingStation cs : chargers) {
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        cout << setw(5) << cs.cityID << setw(25) << cs.nameofCity(cs.cityID) << setw(20) << cs.distanceToSydney << setw(20);
        cout << cs.numberOfChargers << setw(20) << cs.queueLength << setw(18) << cs.calculateQueueLength() << " hours" << endl;
    }
}

