
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
void printBoard() {

    
    // print rows
    for (int i = 0; i < 9; i++){
        // if (i % 3 == 0) {
        //     for (int k = 0; k < 3; k++) {
        //     cout << "  - - - - -  ";
        // }
        // }

            if (i % 3 == 0) {
                cout << "  - - - - -    - - - - -    - - - - -  ";
                cout << endl;
            }
        // print columns
        for (int j = 0; j<9; j++) {
            if (j % 3 == 0) {
                cout << "|";
            }
            char playerSymbol = ' ';
            // print cell and player symbol
            cout  << setw(3) << playerSymbol << "|";
        }
        cout << endl;
        if (i % 3 == 2) {
            cout << "  - - - - -    - - - - -    - - - - -  ";
            cout << endl;
        } else {
            cout << "| -   -   - || -   -   - || -   -   - |";
            cout << endl;
        }
    }
}



void printBoard2() {
    char playerSymbol = ' ';
    for (int gridRow = 0; gridRow < 3; gridRow++){
        cout << "  - - - - -    - - - - -    - - - - -  ";
        cout << endl;

        for (int gameRow = 0; gameRow < 3; gameRow++){

            for (int gridColumn = 0; gridColumn < 3; gridColumn++){
                cout << "|";
                for (int gameColumn = 0; gameColumn < 3; gameColumn++){
                    cout  << setw(3) << gridColumn << "|";
                }
            }
            cout << endl;
            if (gameRow != 2){
                cout << "| -   -   - || -   -   - || -   -   - |";
                cout << endl; 
            }
        }
        cout << "  - - - - -    - - - - -    - - - - -  ";
        cout << endl;
    }
}






















int main() {
    printBoard2();
    return 0;
}