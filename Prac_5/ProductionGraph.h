#include <iostream>
using namespace std;



class ProductionGraph {
public:
    ProductionGraph(int);
    void inputData(int*);
    void graph(int*);
    void getTotal(int&);
    void printAsterisks(int n);
    void createGraph();
    int noPlants;
private:
    int* production; 
};

ProductionGraph::ProductionGraph(int plants)
{
    noPlants = plants;
    production = new int[noPlants];
    
}

void ProductionGraph::inputData(int production[])
{
    for (int i = 1; i <= noPlants; i++)
    {
        cout << endl
             << "Enter production data for plant number "
             << i << endl;
        getTotal(production[i - 1]);
    }
}

void ProductionGraph::getTotal(int& amount)
{
    cout << "Enter a positive integer of units produced by each department, ranging from 1-20.\n" << endl;
    cin >> amount;
    while (amount < 0)
    {
    	    cout<<"input again" << endl;
        cin >> amount;
    }
}

void ProductionGraph::graph(int production[])
{
    cout << "\nUnits produced in units:\n";
    for (int i = 1; i <= noPlants; i++)
    {
        cout << "Plant #" << i << " ";
        printAsterisks(production[i - 1]);
        cout << endl;
    }
}

void ProductionGraph::printAsterisks(int n)
{
    for (int count = 1; count <= n; count++)
        cout << "*";
}

void ProductionGraph::createGraph()
{
    inputData(production);
    graph(production);
    delete[] production;
}

