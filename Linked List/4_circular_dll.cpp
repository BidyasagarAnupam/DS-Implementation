#include <iostream>
using namespace std;

struct node {
    node* prev;
    int data;
    node* next;
};

node* start = NULL;

// Creating a Node In DLL
node* getnode() {
    node* newnode;
    newnode = new node;
    cout << "Enter the data: ";
    cin >> newnode->data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Create a list in CDLL
void create_List(int n) {
    node *newnode, *temp;
    for (int i = 0; i < n; i++) {
        newnode = getnode();
        if (start == NULL) {
            start = newnode;
            newnode->next = start;
            newnode->prev = start;
        } else {
            newnode->prev = start->prev;
            newnode->next = start;
            start->prev->next = newnode;
            start->prev = newnode;
        }
    }
}

void display() {
    node* temp = start;
    if (start == NULL)
        cout << "List is Empty\n";
    else {
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != start);

        cout << "\n";
    }
}

void display_right_to_left() {
    node* temp = start;
    if (start == NULL) {
        cout << "List is Empty\n";
    } else {
        cout << "Contents of the List are: ";
        do {
            temp = temp->prev;
            cout << temp->data << "->";
        } while (temp != start);
    }
    cout << endl;
}

// Insertion of a node at the beginning

void insert_at_begin() {
    node *newnode = getnode(), *temp;
    if (start == NULL) {
        start = newnode;
        newnode->next = start;
        newnode->prev = start;
    } else {
        temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
        start->prev = temp;
        temp->next = start;
    }
}

// Insertion at the end
void insert_at_end() {
    node *newnode = getnode(), *temp;
    if (start == NULL) {
        start = newnode;
        newnode->next = start;
        newnode->prev = start;
    } else {
        temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = start;
        start->prev = newnode;
    }
}

// Insertion at an Intermediate Position

void insert_at_mid() {
    int pos;
    node *newnode = getnode(), *temp;
    if (start == NULL) {
        start = newnode;
        newnode->next = start;
        newnode->prev = start;
    } else {
        temp = start;
        cout << "Enter the position after which you have to insert a node: ";
        cin >> pos;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

// Deleting a node from the beginning
void delete_from_first() {
    node *temp, *ptr;
    if (start == NULL)
        cout << "No Node exits\n";
    else {
        temp = ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        start = start->next;
        start->prev = ptr;
        ptr->next = start;
        free(temp);
    }
}

// Deletion of a Node from the end
void delete_from_end() {
    node *temp, *ptr;
    if (start == NULL)
        cout << "No Node exits\n";
    else {
        temp = ptr = start;
        while (ptr->next != start) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = start;
        start->prev = temp;
        free(ptr);
    }
}

// Deletion of a node at an Intermediate Position

void delete_at_mid() {
    node* temp;
    int pos;
    if (start == NULL)
        cout << "No Node exits\n";
    else {
        temp = start;
        cout << "Enter the intermediate position of a node to be deleted: ";
        cin >> pos;

        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

int main() {
    int n;
    cout << "Enter the number of nodes\n";
    cin >> n;
    create_List(n);
    display();
    display_right_to_left();
    insert_at_begin();
    display();
    display_right_to_left();
    insert_at_end();
    display();
    display_right_to_left();
    insert_at_mid();
    display();
    display_right_to_left();
    delete_from_first();
    display();
    display_right_to_left();
    delete_from_end();
    display();
    display_right_to_left();
    delete_at_mid();
    display();
    display_right_to_left();
}
