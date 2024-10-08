#include <iostream>
#include "DemandGenerator.h"
#include "ChargingAllocation.h"

using namespace std;

int main() {
    DemandGenerator dg;
    ChargingAllocation ca;
    ca.displayVehicles();
    ca.displayChargers();
    ca.allocateCharging();
    ca.printCharging();

    return 0;
}