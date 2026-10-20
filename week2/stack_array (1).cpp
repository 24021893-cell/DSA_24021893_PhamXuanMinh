#include <iostream>
using namespace std;

void insertTail(int a[], int &n, int x);
void deleteTail(int a[], int &n);
void printForward(int a[], int n);

// push: O(1) - them vao cuoi mang
void push(int a[], int &n, int x) {
    insertTail(a, n, x);
}

// pop: O(1) - xoa cuoi mang
void pop(int a[], int &n) {
    deleteTail(a, n);
}

// top: O(1) - doc phan tu cuoi
int top(int a[], int n) {
    if (n == 0) return -1;
    return a[n - 1];
}

int main() {
    int a[1000], n = 0;

    push(a, n, 10);
    push(a, n, 20);
    push(a, n, 30);

    printForward(a, n);
    cout << "Top: " << top(a, n) << '\n';

    pop(a, n);
    printForward(a, n);
    return 0;
}
