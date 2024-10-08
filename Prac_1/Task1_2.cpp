#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    // Prompts user to input the current month and day
    int month, day;
    cout << "Welcome to your friendly weather program.\n"
    << "Enter today's date as two integers for the month and the day:\n";
    cin >> month;
    cin >> day;

    // Seeds the start point of random values generated by rand()
    srand(month * day);
    
    int prediction;
    char ans;
    cout << "Weather for today:\n";
    // Runs the code once and then checks the while loop before running again
    do {
        // Assigns prediction the value of the random number modulo 3
        prediction = rand() % 3;
        // Switches to the case equal to the value of prediction
        switch (prediction) {
            case 0:
                cout << "The day will be sunny!!\n";
                break;
            case 1:
                cout << "The day will be cloudy.\n";
                break;
            case 2:
                cout << "The day will be stormy!.\n";
                break;
            // If he value of pretiction is not "0", "1" or "2" then the default code is run
            default:
                cout << "Weather program is not functioning properly.\n";
        }
        // Prompts the user for an input
        cout << "Want the weather for the next day?(y/n): ";
        // allocates the input to the variable "ans"
        cin >> ans;
        // Returns true to the while loop if the value of "ans" is "y" or "Y" and runs the do loop again
    } while (ans == 'y' || ans == 'Y');
    // If the value of "ans" is not "y" or "Y", the program ends with this output
    cout << "That's it from your 24 hour weather program.\n";
    // Ends the code
    return 0;
}