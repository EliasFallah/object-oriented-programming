#include <iostream>
#include <string>
#include "ChargingStation.h"
#include "Vehicle.h"
#include "DemandGenerator.h"

using namespace std;

int main() {
    for(int i = 0; i < NUM_CITIES; i++) {
        ChargingStation cs(i);
        cout << cs.distanceToSydney(i) << endl;
    }

    for (int i = 0; i < 20; i++) {
        Vehicle v(i);
        cout << v.farthestCity() << endl;
    }

    DemandGenerator dg;
    return 0;
}