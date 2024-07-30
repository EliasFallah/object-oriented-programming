#include<iostream>

using namespace std;

void Swap(int a, int b) {
    int temp;
    
    temp=a;
    a=b;
    b=temp;
}

int main() {
    int a=5;
    int b=8;
    
    cout << "a=" << a << "; b=" << b <<endl;
    
    Swap(a,b);
    
    cout << "a=" << a << "; b=" << b <<endl;
    return 0;
}
