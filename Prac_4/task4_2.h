//Searches a partially filled array of nonnegative integers.
#include <iostream>

using namespace std;

const int DECLARED_SIZE = 10;

class ArraySearch {
    public:
    int arr[DECLARED_SIZE];
    int target;
    int listSize;

    public:
    void fillArray(int*, int , int&);
    int run();
    int search(int*, int, int);
    int newTarget(int&);
    void response(int);
};

void ArraySearch::fillArray(int a[], int size, int& numberUsed)
{
    cout << "Enter up to " << size << " nonnegative integers.\n"
         << "Mark the end of the list with a negative number.\n";
    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size))
    {
        a[index] = next;
        index++;
        cin >> next;
    }

    numberUsed = index;
}

int ArraySearch::search(int a[], int numberUsed, int target)
{
    int index = 0; 
    bool found = false;
    
    //Add your code here for Task 3.1
    while ((found == false) && (index < numberUsed)){
        if (a[index] == target){
            found = true;
            
        }else {
            index++;
        }
    }

    if (found)
        return index;
    else
        return -1;
}

int ArraySearch::newTarget(int& target) {
    cout << "Enter a number to search for: ";
    cin >> target;
}

void ArraySearch::response(int result){
    if (result == -1)
        cout << target << " is not on the list.\n";
    else
        cout << target << " is stored in array position " 
            << result << endl
            << "(Remember: The first position is 0.)\n";
}


int ArraySearch::run(){
    fillArray(arr, DECLARED_SIZE, listSize);
    newTarget(target);
    int result = search(arr, listSize, target);
    response(result);
    return 0;
}

