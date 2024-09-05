//Reads data and displays a bar graph showing productivity for each plant.
#include <iostream>
#include "ProductionGraph.h"

using namespace std;



const int NUMBER_OF_PLANTS = 4;

void inputData(int a[]);

void graph(const int a[]);

void getTotal(int&);
//Reads nonnegative integers from the keyboard

void printAsterisks(int n);
//Prints n asterisks to the screen.


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
