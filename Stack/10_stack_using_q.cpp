#include <bits/stdc++.h>
using namespace std;
const int size = 5;

class Queue {
   private:
    int front, rear, queue[size];

   public:
    Queue() {
        front = -1;
        rear = -1;
    }
    void push(int);
    void pop();
    int Front();
    int capacity();
    bool isEmpty();
};

bool Queue::isEmpty() {
    if (front == -1 && rear == -1) {
        return 1;
    } else {
        return 0;
    }
}


void Queue::push(int x) {
    if (rear == size - 1)
        cout << "Queue overflow\n";
    else {
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        rear++;
        queue[rear] = x;
    }
}

void Queue::pop() {
    if (isEmpty()) {
        cout << "Queue is underflow\n";
    } else {
        front++;
    }
}

int Queue::Front() {
    if (isEmpty()) {
        cout << "Queue is underflow\n";
    } else
        return queue[front];
}

class Stack {
   private:
    Queue q;
   public:
    void push(int);
    void pop();
    int top();
    bool isEmpty();
};