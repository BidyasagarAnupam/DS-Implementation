#include <iostream>
using namespace std;

const int size = 5;
int top1 = -1, top2 = -1, count = 0;
int stack1[size], stack2[size];

void push1(int x) { stack1[++top1] = x; }
void push2(int x) {
    if (top2 == size - 1) {
        cout << "Queue is full\n";
    } else {
        stack2[++top2] = x;
    }
}

int pop1() { return stack1[top1--]; }
int pop2() { return stack2[top2--]; }

void enqueue(int x) {
    if (top1 == size - 1) {
        cout << "Queue is full\n";
    } else {
        push1(x);
        count++;
        cout << "Inserted....\n";
    }
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        cout << "Queue is empty\n";
    } else {
        for (int i = 0; i < count; i++) {
            push2(pop1());
        }
        cout << pop2() << " is deleted\n";
        count--;
        for (int i = 0; i < count; i++) {
            push1(pop2());
        }
    }
}

void display() {
    for (int i = 0; i <= top1; i++) {
        cout << stack1[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    dequeue();
    dequeue();
    display();

    return 0;
}