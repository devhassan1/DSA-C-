/**/#include <iostream>
#include <fstream>

using namespace std;

void FixingCodeInProduction(int* arr, int size, int ToFind) {   //Linear Search with some modifications

	bool numFound = false;
	int ReqIndex= 0;

	for (int i = 0; i < size; i++) {
		if (ToFind == arr[i]) {
			numFound = true;
			ReqIndex = i;
		}
	}
	if (numFound) {
		cout << ReqIndex;
	}
	else
		cout << -1;
}

int main() {
	int size;
	int ToFind;
	ifstream Readff;
	Readff.open("TestCase_05.txt");
	Readff >> ToFind;
	Readff >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		Readff >> arr[i];
		Readff.get();
	}
	FixingCodeInProduction(arr, size, ToFind);
}