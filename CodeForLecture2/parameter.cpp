#include<iostream>

using namespace std;

int f(int x) {
   x = x*x;
   return x;
}

int main() {
    int x = 5;
    cout << "x=" << x << endl;

    cout <<	"square(" << x << ")=" << f(x) << endl;

    cout << "x=" << x << endl;
    
    return 0;
}
