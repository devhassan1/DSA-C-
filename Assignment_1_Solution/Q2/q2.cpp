#include <iostream>
#include <fstream>
#include <string>
using namespace std;
   
int GoingOffTheCharts(int* arr, int size) {  
	int count = 0;
	int consecutiveWorkingHours=0;
	for (int i = 0; i < size ; i++) {
		while(arr[i] > 6 && i < size) {
			count=count+1;
			i++;
		}
		if (consecutiveWorkingHours < count)consecutiveWorkingHours = count;
		count = 0;
	}
	return consecutiveWorkingHours;
}
int main() {
	int size;
	ifstream Readf;
	Readf.open("TestCase_05.txt");
	Readf >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		Readf >> arr[i];
		Readf.get();
	}
	cout << GoingOffTheCharts(arr, size);
}