#include <bits/stdc++.h>
using namespace std;

struct node {
    int info;
    node* next;
};
node* start = NULL;
node* getNode() {
    node* newNode;
    newNode = new node;
    newNode->next = NULL;
    cout << "Enter the data : ";
    cin >> newNode->info;
    return newNode;
}

void createList(int size) {
    node *newNode, *temp;
    for (int i = 1; i <= size; i++) {
        newNode = getNode();
        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insert_begin() {
    node* newNode;
    newNode = getNode();
    if (start == NULL) {
        start = newNode;
    } else {
        newNode->next = start;
        start = newNode;
    }
    cout << "Insert at begin done\n";
}

void insert_end() {
    node *newNode, *temp;
    newNode = getNode();
    if (start == NULL) {
        start = newNode;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Insert at end done\n";
}

void insert_mid() {
    node *newNode, *temp;
    int pos;
    newNode = getNode();
    if (start == NULL) {
        start = newNode;
    } else {
        temp = start;
        cout << "Enter the position after which node to be placed: ";
        cin >> pos;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    cout << "Insert at mid done\n";
}

void delete_first() {
    int data;
    if (start == NULL) {
        cout << "No node exsit\n";
    } else {
        data = start->info;
        cout << data << " deleted succefully\n";
        node* temp = start;
        start = temp->next;
        delete (temp);
    }
    cout << "Delete from begin done\n";
}

void delete_last() {
    int data;
    if (start == NULL) {
        cout << "No node exsit\n";
    } else {
        node* temp = start;
        node* ptr = start;
        while (temp->next != NULL) {
            ptr = temp;
            temp = temp->next;
        }
        data = temp->info;
        cout << data << " deleted\n";
        ptr->next = NULL;
        delete (temp);
    }
    cout << "Delete from last done\n";
}

void delete_mid() {
    int pos;
    node *ptr, *temp;
    ptr = temp = start;
    cout << "Enter the position to be deleted: ";
    cin >> pos;
    for (int i = 1; i < pos; i++) {
        ptr = temp;
        temp = temp->next;
    }
    int data = temp->info;
    cout << data << " deleted\n";
    ptr->next = temp->next;
    delete (temp);
    cout << "Delete from mid done\n";
}

void display() {
    node* temp = start;
    cout << "The data are\n";
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    createList(5);
    display();
    insert_begin();
    display();
    insert_end();
    display();
    insert_mid();
    display();
    delete_first();
    display();
    delete_last();
    display();
    delete_mid();
    display();

    return 0;
}