#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void BribedQueue(int* arr, int size) {     //Bubble Sort
	int bribes = 0;
	for (int i = 0; i < size-1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				bribes++;
			}	
		}
	}          
	cout << bribes;
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
	BribedQueue(arr, size);
	
}
/* 
 }*/