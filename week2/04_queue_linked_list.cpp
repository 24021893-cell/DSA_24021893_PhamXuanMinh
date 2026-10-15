#include <iostream>
using namespace std;

// Reuse struct Node va cac ham Linked List da co
struct Node {
    int data;
    Node* next;
};

Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void insertTail(Node*& head, int x) {
    Node* p = createNode(x);

    if (head == nullptr) {
        head = p;
        return;
    }

    Node* q = head;
    while (q->next != nullptr)
        q = q->next;

    q->next = p;
}

void deleteHead(Node*& head) {
    if (head == nullptr) return;

    Node* p = head;
    head = head->next;
    delete p;
}

void printForward(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';
}

// Queue: FIFO
void enqueue(Node*& front, int x) {
    insertTail(front, x);
}

void dequeue(Node*& front) {
    deleteHead(front);
}

int frontValue(Node* front) {
    if (front == nullptr) {
        cout << "Queue rong!\n";
        return -1;
    }
    return front->data;
}

int main() {
    Node* front = nullptr;

    enqueue(front, 10);
    enqueue(front, 20);
    enqueue(front, 30);

    cout << "Queue sau khi enqueue: ";
    printForward(front);
    cout << "Front = " << frontValue(front) << '\n';

    dequeue(front);

    cout << "Queue sau khi dequeue: ";
    printForward(front);

    while (front != nullptr) dequeue(front);
    return 0;
}
