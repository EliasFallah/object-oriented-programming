#include<iostream>
using namespace std;

void twodigits(int original, int& first, int& second) {
   first = original / 10;
   second = original - first * 10;
}

int main(){

int original = 95;
int first = 0;
int second = 0;

twodigits(original, first, second);

cout << original << " => " << first << " and " << second << endl;

return 0;
} 
