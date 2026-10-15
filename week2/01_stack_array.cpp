#include <iostream>
using namespace std;

// Reuse cac ham List mang da co
void insertTail(int a[], int &n, int x) {
    a[n++] = x;
}

void deleteTail(int a[], int &n) {
    if (n > 0) n--;
}

void printForward(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
}

// Stack: LIFO (vao sau, ra truoc)
void push(int a[], int &n, int x) {
    insertTail(a, n, x);
}

void pop(int a[], int &n) {
    deleteTail(a, n);
}

int peek(int a[], int n) {
    if (n == 0) {
        cout << "Stack rong!\n";
        return -1;
    }
    return a[n - 1];
}

int main() {
    int a[100];
    int n = 0;

    push(a, n, 10);
    push(a, n, 20);
    push(a, n, 30);

    cout << "Stack sau khi push: ";
    printForward(a, n);
    cout << "Top = " << peek(a, n) << '\n';

    pop(a, n);

    cout << "Stack sau khi pop: ";
    printForward(a, n);

    return 0;
}
