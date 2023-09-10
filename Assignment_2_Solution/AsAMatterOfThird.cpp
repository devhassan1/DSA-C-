#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int ID;
	Node* next;
	Node* prev;
};

Node* start = nullptr;
Node* temp = (struct Node*)malloc(sizeof(struct Node));


void insert(int b) {
	Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->ID = b;
	temp->next = nullptr;
	if (start == nullptr) {
		start = temp;
		start->prev = nullptr;
	}
	else {
		struct Node* current = start;
		while (current->next != nullptr) {
			current = current->next;
		}
			current->next = temp;
			temp->prev = current;
		}
	}

void Print() {
	int c = 1;
	Node* nodePtr = start;
	while (nodePtr->next != nullptr) {
		nodePtr = nodePtr->next;
		 c = c + 1;
	}
	if (c < 3) {
		cout << -1;
	}
	nodePtr = nodePtr->prev;
	nodePtr = nodePtr->prev;
	cout << nodePtr->ID;
}

int main() {
	int b = 0;
	int valid = 0;
	ifstream Readff;
	Readff.open("Test01.txt");
	while (valid != -1 && valid != 10) {     //-1 is checked because when there is no data to read, .Get() returns -1.
		Readff >> b;                         //10 is checked because get() returns 10 for nextline (ascii code) 
		if (b>0){
		insert(b);
		}
		valid= Readff.get();
	}
	Print();
}
