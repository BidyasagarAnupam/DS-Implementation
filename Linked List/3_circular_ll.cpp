#include <bits/stdc++.h>
using namespace std;

struct node {
    int info;
    node *next;
};
node *start = NULL;

node *getNode() {
    node *newNode = new node;
    cout << "Enter the data: ";
    cin >> newNode->info;
    newNode->next = NULL;
    return newNode;
}

void create_circular_list(int size) {
    node *ptr, *temp;
    for (int i = 1; i <= size; i++) {
        ptr = getNode();
        if (start == NULL) {
            start = ptr;
        } else {
            temp = start;
            while (temp->next != NULL) temp = temp->next;
            temp->next = ptr;
        }
    }
    ptr->next = start;
}

void display() {
    node *temp;
    temp = start;
    if (start == NULL) {
        cout << "Empty List\n";
    } else {
        cout << "List are\n";
        do {
            cout << temp->info << " ";
            temp = temp->next;
        } while (temp != start);
    }
}

void insert_begin() {
    node *ptr, *temp;
    ptr = getNode();
    if (start == NULL) {
        start = ptr;
        ptr->next = start;
    } else {
        temp = start;
        while (temp->next != start) temp = temp->next;
        ptr->next = start;
        start = ptr;
        temp->next = start;
    }
    cout << "Insert begin\n";
}

void insert_end() {
    node *ptr, *temp;
    ptr = getNode();
    if (start == NULL) {
        start = ptr;
        ptr->next = start;
    } else {
        temp = start;
        while (temp->next != start) temp = temp->next;
        temp->next = ptr;
        ptr->next = start;
    }
    cout << "Insert end\n";
}

void insert_mid() {
    node *ptr, *temp;
    ptr = getNode();
    if (start == NULL) {
        start = ptr;
        ptr->next = start;
    } else {
        int pos;
        cout << "Enter the postion after which node entered: ";
        cin >> pos;
        temp = start;
        for (int i = 1; i < pos; i++) temp = temp->next;
        ptr->next = temp->next;
        temp->next = ptr;
    }
    cout << "Insert mid\n";
}

void delete_begin() {
    node *ptr, *temp;
    if (start == NULL) {
        cout << "Empty\n";
    } else if (start->next == start) {
        ptr = start;
        delete (ptr);
        cout << "Delete from begin\n";
    } else {
        temp = ptr = start;
        while (temp->next != start) temp = temp->next;
        start = start->next;
        temp->next = start;
        delete (ptr);
        cout << "Delete from begin\n";
    }
}

void delete_end() {
    node *ptr, *temp;
    if (start == NULL) {
        cout << "Empty\n";
    } else if (start->next == start) {
        ptr = start;
        delete (ptr);
    } else {
        temp = ptr = start;
        while (temp->next != start) {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = start;
        delete (temp);
    }
    cout << "Delete from end\n";
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
    ptr->next = temp->next;
    delete (temp);
    cout << "Delete from mid done\n";
}


int main() {
    create_circular_list(5);
    display();
    insert_begin();
    display();
    insert_mid();
    display();
    insert_end();
    display();
    delete_begin();
    display();
    delete_mid();
    display();
    delete_end();
    display();
    return 0;
}