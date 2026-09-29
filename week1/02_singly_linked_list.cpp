#include <iostream>
using namespace std;

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

void insertAt(Node*& head, int k, int x) {
    if (k < 0) return;

    if (k == 0) {
        insertHead(head, x);
        return;
    }

    Node* q = head;
    for (int i = 0; i < k - 1 && q != nullptr; i++)
        q = q->next;

    if (q == nullptr) return;

    Node* p = createNode(x);
    p->next = q->next;
    q->next = p;
}

void deleteHead(Node*& head) {
    if (head == nullptr) return;

    Node* p = head;
    head = head->next;
    delete p;
}

void deleteTail(Node*& head) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* q = head;
    while (q->next->next != nullptr)
        q = q->next;

    delete q->next;
    q->next = nullptr;
}

void deleteAt(Node*& head, int k) {
    if (head == nullptr || k < 0) return;

    if (k == 0) {
        deleteHead(head);
        return;
    }

    Node* q = head;
    for (int i = 0; i < k - 1 && q->next != nullptr; i++)
        q = q->next;

    if (q->next == nullptr) return;

    Node* p = q->next;
    q->next = p->next;
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

void printBackward(Node* head) {
    if (head == nullptr) return;

    printBackward(head->next);
    cout << head->data << " ";
}

int main() {
    Node* head = nullptr;

    insertTail(head, 10);
    insertTail(head, 20);
    insertTail(head, 30);
    insertTail(head, 40);

    cout << "Ban dau: ";
    printForward(head);

    insertHead(head, 5);
    insertTail(head, 50);
    insertAt(head, 2, 99);

    cout << "Sau khi chen: ";
    printForward(head);

    deleteHead(head);
    deleteTail(head);
    deleteAt(head, 2);

    cout << "Sau khi xoa: ";
    printForward(head);

    cout << "Duyet nguoc: ";
    printBackward(head);
    cout << '\n';
}
