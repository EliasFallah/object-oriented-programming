#include <iostream>
#include <string>
using namespace std;

void sort(int a, int b, int c) {
    int x = 0;
    // check if sorting is complete
    while (a > b || b > c){
        if(a>b){
            // swap a and b values
            x = a;
            a = b;
            b = x;
        } 
        if (b > c){
            // swap b and c values
            x = b;
            b = c;
            c = x;
        }
    }

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

int main(){
    sort(18, 15, 8);
}