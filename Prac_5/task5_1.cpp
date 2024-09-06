//Reads data and displays a bar graph showing productivity for each plant.
#include <iostream>
#include "ProductionGraph.h"

using namespace std;


int main( )
{
    int plants;
    cout << "This program displays a graph showing\n"
         << "production for each plant in the company.\n";

    cout << "Enter the number of plants: ";
    cin >> plants;

      ProductionGraph productionGraph(plants);   

    productionGraph.createGraph();

    

    return 0;
}
