#include "ArrayQueue.h"
#include "ArrayList.h"

// Constructor: O(1) time, O(capacity) space for the array.
ArrayQueue::ArrayQueue(int size) {
    capacity = size > 0 ? size : 100;
    a = new int[capacity];
    n = 0;
}

// Destructor: O(1) time to release the allocated array.
ArrayQueue::~ArrayQueue() {
    delete[] a;
}

// enqueue: O(1), assuming insertTail appends without shifting; O(1) extra space.
void ArrayQueue::enqueue(int data) {
    if (n >= capacity) return;
    insertTail(a, n, data);
}

// dequeue: O(n), because deleteHead shifts the remaining array elements left.
int ArrayQueue::dequeue() {
    if (isEmpty()) return -1;
    int value = front();
    deleteHead(a, n);
    return value;
}

// front: O(1) time and O(1) extra space.
int ArrayQueue::front() {
    if (isEmpty()) return -1;
    return a[0];
}

// isEmpty: O(1) time and O(1) extra space.
bool ArrayQueue::isEmpty() {
    return n == 0;
}
