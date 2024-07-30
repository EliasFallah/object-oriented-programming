#include<iostream>
using namespace std;

void time(int secs=0, int mins=0, int hrs=0) {
	cout << hrs << ":" << mins << ":" << secs << endl;
}

int main()
{
	time();
	time(34);
	time(34,15);
	time(34,15,1);
	return 0;
}
