#include<iostream>

using namespace std;

void Swap(int& x, int& y) {
    int temp;

    temp=x;
    x=y;
    y=temp;
}

int main() {
    int a=5;
    int b=8;

    cout << "a=" << a << "; b=" << b <<endl;

    Swap(a,b);

    cout << "a=" << a << "; b=" << b <<endl;
}
