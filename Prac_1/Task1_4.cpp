#include <iostream>
#include <string>
using namespace std;

int main() {
    for(int i=1; i <= 10; i++){
        for(int j=1; j <= 10; j++){
            int result = j*i;
            cout << result;
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}