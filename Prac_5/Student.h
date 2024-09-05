#include <iostream>
#include <string>
using namespace std;


class Student
{
private:
    string name;
    int numUnits;
    string* unitList;

public:
    Student(string, int);
    void allocateUnits();
    void printUnits();
    int generateStudent();

};

Student::Student(string name, int numUnits)
{
    this->name = name;
    this->numUnits = numUnits;
    unitList = new string[numUnits];
}

void Student::allocateUnits() {
    for (int i = 0; i < numUnits; i++) {
        cout << "Enter unit name: ";
        cin >> unitList[i];
    }
}

void Student::printUnits() {
    cout << "\nStudent: " << name << endl;
    cout << "Units: ";
    for (int i = 0; i < numUnits; i++) {
        cout << unitList[i] << " ";
    }
    cout << endl;
}

int Student::generateStudent() {
    allocateUnits();
    printUnits();
    delete[] unitList;
    return 0;
}
