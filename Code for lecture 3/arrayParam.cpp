#include <iostream> 
using namespace std;

void printOneDimension(int data[]){
    int j;
	for(j = 0; j<3; j++) {
		cout << data[j] << "   ";
	}

	cout << endl;
}

void printAll(int data[3][3]) {
	for(int i = 0;i<3; i++) {
	   for(int j=0;j<3;j++)
			cout << data[i][j];
	   cout << endl;
    }

    cout << endl;
}

int main()  
{
    int a[3][3] = {{1,2,3},{10,20,30}, {100,200,300}};
    printOneDimension(a[2]);
    printAll(a);
   return 0;                         
}

