#include <iostream>
using namespace std;
const int size = 5;
int stack[size];
int top = -1;

void push() {
    int x;

    if (top == size - 1) {
        cout << "Stack is overflow\n";
    } else {
        cout << "Enter the data\n";
        cin >> x;
        stack[++top] = x;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is underflow\n";
    } else {
        cout << "Element " << stack[top--] << " is deleted\n";
    }
}

void display() {
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    push();
    push();
    push();
    push();
    push();
    push();
    display();
    pop();
    display();
    return 0;
}
