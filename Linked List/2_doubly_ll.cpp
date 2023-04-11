#include <bits/stdc++.h>
using namespace std;

struct node {
    int info;
    node* next;
    node* prev;
};
node* start = NULL;
node* getNode() {
    node* newNode;
    newNode = new node;
    cout << "Enter the data: ";
    cin >> newNode->info;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void createDll(int size) {
    node *newNode, *temp;
    for (int i = 1; i <= size; i++) {
        newNode = getNode();
        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "inserted\n";
    }
}

void insert_begin() {
    node* newNode = getNode();
    if (start == NULL) {
        start = newNode;
    } else {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
    cout << "Insert begin\n";
}
void insert_end() {
    node* newNode = getNode();
    if (start == NULL) {
        start = newNode;
    } else {
        node* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Insert End\n";
}

void insert_mid() {
    node* newNode = getNode();
    if (start == NULL) {
        start = newNode;
    } else {
        int pos;
        cout << "Enter the postion after which: ";
        cin >> pos;
        node* temp = start;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }
    cout << "Insert mid\n";
}

void delete_begin() {
    node* temp;
    if (start == NULL) {
        cout << "List is empty\n";
    } else {
        temp = start;
        start = start->next;
        start->prev = NULL;
        delete (temp);
    }
    cout << "Delete begin\n";
}
void delete_end() {
    node* temp;
    if (start == NULL) {
        cout << "List is empty\n";
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete (temp);
    }
    cout << "Delete end\n";
}

void delete_mid() {
    node* temp;
    if (start == NULL) {
        cout << "List is empty\n";
    } else {
        int pos;
        cout << "Enter the postion of node to be deleted: ";
        cin >> pos;
        temp = start;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete (temp);
    }
}

void display() {
    cout << "Left to right\n";
    node* temp = start;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

void traverser_right_to_left() {
    cout << "Right to left\n";
    node* temp = start;
    while (temp->next != NULL) temp = temp->next;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    createDll(5);
    display();
    traverser_right_to_left();
    insert_begin();
    display();
    traverser_right_to_left();
    insert_end();
    display();
    traverser_right_to_left();
    insert_mid();
    display();
    traverser_right_to_left();
    delete_begin();
    display();
    traverser_right_to_left();
    delete_end();
    display();
    traverser_right_to_left();
    delete_mid();
    display();
    traverser_right_to_left();
}