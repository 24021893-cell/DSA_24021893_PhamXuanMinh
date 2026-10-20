#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertHead(Node*& head, int x);
void deleteHead(Node*& head);
void printForward(Node* head);

// push: O(1) - them vao dau danh sach
void push(Node*& head, int x) {
    insertHead(head, x);
}

// pop: O(1) - xoa dau danh sach
void pop(Node*& head) {
    deleteHead(head);
}

// top: O(1) - doc node dau
int top(Node* head) {
    if (head == nullptr) return -1;
    return head->data;
}

int main() {
    Node* head = nullptr;

    push(head, 10);
    push(head, 20);
    push(head, 30);

    printForward(head);
    cout << "Top: " << top(head) << '\n';

    pop(head);
    printForward(head);

    while (head != nullptr) deleteHead(head);
    return 0;
}
