#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertTail(Node*& head, int x);
void deleteHead(Node*& head);
void printForward(Node* head);

// enqueue: O(n) - insertTail phai duyet tu dau den cuoi
void enqueue(Node*& front, int x) {
    insertTail(front, x);
}

// dequeue: O(1) - xoa node dau
void dequeue(Node*& front) {
    deleteHead(front);
}

// frontValue: O(1) - doc node dau
int frontValue(Node* front) {
    if (front == nullptr) return -1;
    return front->data;
}

int main() {
    Node* front = nullptr;

    enqueue(front, 10);
    enqueue(front, 20);
    enqueue(front, 30);

    printForward(front);
    cout << "Front: " << frontValue(front) << '\n';

    dequeue(front);
    printForward(front);

    while (front != nullptr) deleteHead(front);
    return 0;
}
