
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int ID;
	Node* next;
};

Node* start = nullptr;
Node* center = nullptr;
Node* temp = (struct Node*)malloc(sizeof(struct Node));
int counter=0;

void ADD(int td) {
	Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->ID = td;
	temp->next = nullptr;
	if (start == nullptr) {
		start = temp;
		center = temp;
	}
	else {
		struct Node* current = start;
		struct Node* prev = nullptr;
		while (current != nullptr) {
			prev = current;
			current = current->next;
		}
		prev->next = temp;

		if (counter % 2 == 0) {
			center = center->next;
		}
	}
	counter++;
};

void Delete() {
	if (start == nullptr) {
		cout << "no elements in the list" << endl;
		return;
     }
	Node* current = start;
	Node* prev = nullptr;
	while (current->next!=nullptr) {
		prev = current;
		current = current->next;
	}
	if (current == center) {
		center = prev;
	}
	if (prev == nullptr) {
		start = nullptr;
	}
	else {
		prev->next = nullptr;
	}
	free(current);
	counter--;
};

void GetTrump() {
	if (counter == 0) {
		cout << "no lucky winners today. " <<endl;
	}
	else if(counter % 2 == 0) {
		cout << "winners are: " << center->ID<< endl;
		center = center->next;
		cout << center->ID << endl;
	}
	else if(counter % 2 != 0) {
		cout << "lucky winner is : " << center->ID << endl;
	}
}

int main() {
	int td = 0;
	string alpha;
	ifstream Readff;
	Readff.open("Test05.txt");
	alpha = Readff.get();
	while (alpha!= "E") {  //E is read for END Command
		if (alpha == "A") { //A is read for ADD command
			Readff.seekg(3, ios::cur);  //seekg is used to move cursor for n times here we already have read A. So in orde to read the number we have to move 3
			Readff >> td;                 //3 steps (D,D, Space)
			ADD(td);
			Readff.get();
		}
		if (alpha == "D") {  //d is read for delete command
			Delete();
			Readff.seekg(7, ios::cur);
		}
		alpha = Readff.get();
	}
	GetTrump();
}