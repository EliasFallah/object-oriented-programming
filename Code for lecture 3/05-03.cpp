//Demonstrates an array parameter.
#include <iostream>
using namespace std;

void printArray(int a[], int length) {
  for (int i = 0; i < length; i++)
    cout << a[i] << " ";

  cout << endl;
}
int main() {
  int a[] = { 1, 2, 3, 4, 5 };
  int b[] = { 4,-1,3,20,7,9,4,11,-2};
  printArray(a, 5);
  printArray(b, 9);
  return 0;
}
