/*
DECLARATION
I hold a copy of this assignment that I can produce if the original is lost or damaged.
I hereby certify that no part of this assignment has been copied from any other student’s work or
from any other source except where due acknowledgement is made in the assignment. No part
of this assignment has been written/produced for me by another person except where such
collaboration has been authorised by the subject lecturer concerned.
*/
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