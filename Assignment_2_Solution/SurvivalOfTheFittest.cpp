#include <iostream>
#include <fstream>

using namespace std;

const int MAX_RANGE = 100000; // Change this according to the maximum range of numbers

struct Node {
    int ID;
    Node* next;
    Node* prev;
};

Node* start = nullptr;

// Function to insert a number into the linked list
void insert(int b) {
    Node* temp = new Node();
    temp->ID = b;
    temp->next = nullptr;
    if (start == nullptr) {
        start = temp;
        start->prev = nullptr;
    }
    else {
        Node* current = start;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;
    }
}

// Function to perform counting sort on numbersread from the text file
void countingSort(int arr[], int n) {
    int count[MAX_RANGE] = { 0 };


    for (int i = 0; i < n; i++) {
        count[arr[i]]++;//counter will bw incremented as soon s a number is stored in the array.
    }

    int index = 0;
    // sorting
    for (int i = 0; i < MAX_RANGE; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

double findMedian() {
    int count = 0;
    Node* nodePtr = start;

    while (nodePtr != nullptr) {
        count++;
        nodePtr = nodePtr->next;
    }

    int* arr = new int[count];
    nodePtr = start;

    // Copy elements from the linked list to an array
    for (int i = 0; i < count; i++) {
        arr[i] = nodePtr->ID;
        nodePtr = nodePtr->next;
    }

    countingSort(arr, count);

    // if the no of elements are odd
    if (count % 2 == 1) {
        return arr[count / 2];
    }
    else {
        int mid1 = arr[(count - 1) / 2];
        int mid2 = arr[count / 2];
        return (mid1 + mid2) / 2.0;
    }
}

int main() {
    int b = 0;
    ifstream Readff;
    Readff.open("Test01.txt");
    while (Readff >> b) {
        if (b > 0) {
            insert(b);
            double median = findMedian();
            if (median != -1.0) {
                cout << "Median: " << median << endl;
            }
        }
    }
    return 0;
}
