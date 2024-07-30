#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // initialise variables
    int bestUnderCable = 0;
    int bestOverCable = 0;
    double bestPrice = 0;
    bool bestPriceSet = false;

    int riverWidth;
    int factoryDistance;
    int underCableCost;
    int overCableCost;

    cout << "Width of the river: " << endl;
    cin >> riverWidth;

    cout << "Distance to the factory: " << endl;
    cin >> factoryDistance;

    cout << "Price per meter of overland cable: " << endl;
    cin >> overCableCost;

    cout << "Price per meter of underwater cable: " << endl;
    cin >> underCableCost;

    int sqrRiverWidth = riverWidth * riverWidth;
    // iterate through all lengths of over land cable
    for (int overCable = 1; overCable <= factoryDistance; overCable += 100){
        // Calcxulate the length of the under water cable
        int underCableLength = 8000 - overCable;
        int sqrUnderCableLength = underCableLength * underCableLength;
        double underCable = sqrt(sqrRiverWidth + sqrUnderCableLength);

        // Calculate the price of the cable run
        double overCablePrice = overCable * overCableCost;
        double underCablePrice = underCable * underCableCost;
        double totalPrice = overCablePrice + underCablePrice;

        // checks if the calculated price is lower then the best price
        if (totalPrice < bestPrice){
            bestUnderCable = underCable;
            bestOverCable = overCable;
            bestPrice = totalPrice;
        } // Sets ther best price on the first for loop 
        else if (bestPriceSet == false){
            bestUnderCable = underCable;
            bestOverCable = overCable;
            bestPrice = totalPrice;
            bestPriceSet = true;
        }


        
    }
    cout << "Lowest cost cable run\n" << endl;
    cout << "Cable above ground: " << bestOverCable << "m" << endl;
    cout << "Cable under river: " << bestUnderCable << "m" << endl;
    cout << "Price: $" << bestPrice << endl;
}

