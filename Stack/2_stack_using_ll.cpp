#include <iostream>
using namespace std;

struct stack {
    int data;
    stack *next;
};

stack *head = NULL;

stack *getnode() {
    stack *newnode = new stack;
    cout << "Enter the data\n";
    cin >> newnode->data;
    newnode->next = NULL;
    return newnode;
}

void push() {
    stack *newnode = getnode();
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}
void pop() {
    stack *temp = head;
    if (head == NULL) {
        cout << "Stack is underflow\n";
    } else {
        cout<<head->data<<" is deleted\n";
        head = head->next;
        delete (temp);
    }
}

void display() {
    stack *temp= head;
    if(head == NULL) {
        cout<<"Stack is underflow\n";
    } else {
        while(temp != NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

int main() {
    push();
    push();
    push();
    push();
    display();
    pop();
    display();

    return 0;
}