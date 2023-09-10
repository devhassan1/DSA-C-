#include <iostream>
#include <fstream>

using namespace std;

int td;
int tr;
int notrans;
int fraudtr;
int fraudtd;

struct Bank {
	int TransactionID;
	int transam;
	Bank* next;
};

Bank* temp = (struct Bank*)malloc(sizeof(struct Bank));
Bank* start = nullptr;

void Read(int td, int tr) {
	Bank* temp = (struct Bank*)malloc(sizeof(struct Bank));
	temp->TransactionID = td;
	temp->transam = tr;
	temp->next = nullptr;
	if (start == nullptr) {
		start = temp;
	}
	else {
		struct Bank* current = start;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = temp;
	}
};


void RemPrint() {
	Bank* p1 = start;
	while (p1 != nullptr) {
		cout << p1->TransactionID << endl;
		cout << p1->transam << endl;
		p1 = p1->next;
	}
}

void Delete(int fraudtd) {
	if (start == nullptr) {
		return;
	}
	if (fraudtd == start->TransactionID) {
	Bank* curr = start;
	start = start->next;
	free(curr);
	}
	else {
		Bank* prev = start;
		Bank* curr = start->next;
		while (curr != nullptr) {
			if (fraudtd == curr->TransactionID) {
				prev->next = curr->next;
				free(curr);
				break;
			}
			prev = prev->next;
			curr = curr->next;
		}
	}
}

int main() {

	ifstream Readff;
	Readff.open("Test05.txt");
	Readff >> notrans;
	cout << notrans << endl;
	Readff.get();
	Readff >> fraudtr;
	cout << fraudtr << endl;
	for (int i = 0; i < notrans; i++) {
		Readff >> td;
		Readff.get();
		Readff >> tr;
		Read(td, tr);
		Readff.ignore();
	}
	for (int i = 0; i < fraudtr; i++) {
		Readff >> fraudtd;
		cout << fraudtd << endl;
		Delete(fraudtd);
	}
	RemPrint();
}