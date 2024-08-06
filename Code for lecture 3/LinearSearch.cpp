#include<iostream>

using namespace std;

int linearSearch(int scores[ ], int size, int lookFor)
{
    bool found = false;
    int  index;
    for( index  = 0; index<=size && !found; index++ ) {
         if ( scores[index] == lookFor )
             found = true;
    }

    if (found)
        return index;
    else
        return -1;
  }  // end linearSearch


int main(){
	int array[10] = {43,52,45,2,54,32,5,67,86,98};

	cout << "The numbers are: ";
	for(int i=0;i<10;i++){
		cout << array[i] << " ";
	}

	cout << endl;

	if (linearSearch(array, 10, 2)>0)
		cout << "Found it!" << endl;
	else
		cout << "Did not find it!" << endl;

	return 0;

}

