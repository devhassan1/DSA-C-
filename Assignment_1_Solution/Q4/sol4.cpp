#include <iostream>
#include <fstream>

using namespace std;

void SelectingTheMedian(int* arr, int size) {   //Binary Search with some modifications

	int current, j, k;
	
	for (int i = 1; i < size; i++) {
		 current = arr[i];
		 k = i;
		 j = i - 1;
		while ( j >= 0) {
			if (current < arr[j]) {
				swap(arr[k], arr[j]);
			}
			j=j-1;
			k = k - 1;
		}
	}	
	int mid = (size+1) / 2;
	int median = arr[mid-1];
	cout << median << endl;
   }

int main() {
	int size;
	ifstream Readff;
	Readff.open("TestCase_05.txt");
	Readff >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		Readff >> arr[i];
		Readff.get();
	}
	SelectingTheMedian(arr, size);

}
