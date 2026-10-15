#include <iostream>
using namespace std;

// Reuse cac ham List mang da co
void insertTail(int a[], int &n, int x) {
    a[n++] = x;
}

void deleteHead(int a[], int &n) {
    if (n == 0) return;
    for (int i = 0; i < n - 1; i++) a[i] = a[i + 1];
    n--;
}

void printForward(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
}

// Queue: FIFO (vao truoc, ra truoc)
void enqueue(int a[], int &n, int x) {
    insertTail(a, n, x);
}

void dequeue(int a[], int &n) {
    deleteHead(a, n);
}

int frontValue(int a[], int n) {
    if (n == 0) {
        cout << "Queue rong!\n";
        return -1;
    }
    return a[0];
}

int main() {
    int a[100];
    int n = 0;

    enqueue(a, n, 10);
    enqueue(a, n, 20);
    enqueue(a, n, 30);

    cout << "Queue sau khi enqueue: ";
    printForward(a, n);
    cout << "Front = " << frontValue(a, n) << '\n';

    dequeue(a, n);

    cout << "Queue sau khi dequeue: ";
    printForward(a, n);

    return 0;
}
