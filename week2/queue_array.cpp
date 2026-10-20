#include <iostream>
using namespace std;

void insertTail(int a[], int &n, int x);
void deleteHead(int a[], int &n);
void printForward(int a[], int n);

// enqueue: O(1) - them vao cuoi mang
void enqueue(int a[], int &n, int x) {
    insertTail(a, n, x);
}

// dequeue: O(n) - xoa dau mang va dich cac phan tu sang trai
void dequeue(int a[], int &n) {
    deleteHead(a, n);
}

// frontValue: O(1) - doc phan tu dau
int frontValue(int a[], int n) {
    if (n == 0) return -1;
    return a[0];
}

int main() {
    int a[1000], n = 0;

    enqueue(a, n, 10);
    enqueue(a, n, 20);
    enqueue(a, n, 30);

    printForward(a, n);
    cout << "Front: " << frontValue(a, n) << '\n';

    dequeue(a, n);
    printForward(a, n);
    return 0;
}
