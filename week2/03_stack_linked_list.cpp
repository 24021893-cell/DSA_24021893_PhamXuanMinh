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

void insertHead(Node*& head, int x) {
    Node* p = createNode(x);
    p->next = head;
    head = p;
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

// Stack: LIFO
void push(Node*& top, int x) {
    insertHead(top, x);
}

void pop(Node*& top) {
    deleteHead(top);
}

int peek(Node* top) {
    if (top == nullptr) {
        cout << "Stack rong!\n";
        return -1;
    }
    return top->data;
}

int main() {
    Node* top = nullptr;

    push(top, 10);
    push(top, 20);
    push(top, 30);

    cout << "Stack sau khi push: ";
    printForward(top);
    cout << "Top = " << peek(top) << '\n';

    pop(top);

    cout << "Stack sau khi pop: ";
    printForward(top);

    while (top != nullptr) pop(top);
    return 0;
}
