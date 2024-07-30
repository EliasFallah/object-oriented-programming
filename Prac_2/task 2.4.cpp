#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // initialise variables
    int bestUnderCable = 0;
    int bestOverCable = 0;
    double bestPrice = 0;
    int riverWidth = 5000;
    int sqrRiverWidth = riverWidth * riverWidth;
    // iterate through all lengths of over land cable
    for (int overCable = 1; overCable <= 8000; overCable += 100){
        // Calcxulate the length of the under water cable
        int sqrOverCable = overCable * overCable;
        double underCable = sqrt(sqrRiverWidth + sqrOverCable);
        cout << "\nlength = " << underCable << endl;
        // Calculate the price of the cable run
        double overCablePrice = overCable * 70;
        double underCablePrice = underCable * 80;
        double totalPrice = overCablePrice + underCablePrice;
        cout << "$" << totalPrice << endl;
    }
}

