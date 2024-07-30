#include <iostream>
#include <string>
using namespace std;

// function containing default variables
void testDefaultArg(int day = 1, string month= "Jan",
int year = 2023) {
cout << "Today is " << day <<" "
<< month << " " << year << endl;
}

// each function overides default variables if they alternatives are included when the function is called
int main() {
    testDefaultArg();
    testDefaultArg(10);
    testDefaultArg(10, "Jul");
    testDefaultArg(10, "Jul", 2024);
}