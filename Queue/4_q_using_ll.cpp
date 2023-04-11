#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

node *front = NULL;
node *rare = NULL;

node *getnode() {
    node *newnode = new node;
    cout << "Enter the data\n";
    cin >> newnode->data;
    newnode->next = NULL;
}

void enqueue() {
    node *newNode = getnode();
    if (front == 0 && rare == 0) {
        front = rare = newNode;
    } else {
        rare->next = newNode;
        rare = newNode;
    }
}

void dequeue() {
    node *temp = front;
    if (front == 0 && rare == 0) {
        cout << "Queue is empty\n";
    } else {
        front = front->next;
        delete (temp);
    }
}

void display() {
    node *temp = front;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int main() {
    enqueue();
    enqueue();
    enqueue();
    display();
    dequeue();
    display();
    return 0;
}
