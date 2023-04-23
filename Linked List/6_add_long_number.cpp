#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

node *getData(int val) {
    node *newNode = new node;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void insert(node *&start, int d) {
    node *newNode = getData(d);
    newNode->next = start;
    start = newNode;
}

void display(node *start) {
    node *temp = start;
    do {
        cout << temp->data;
        temp = temp->next;
    } while (temp != NULL);
    cout << endl;
}
node *numberAdd(node *b, node *a) {
    int carry = 0;
    node *start = NULL;
    while (b != NULL || a != NULL) {
        int sum = carry;
        if (b != NULL) {
            sum += b->data;
            b = b->next;
        }
        if (a != NULL) {
            sum += a->data;
            a = a->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        insert(start, sum);
    }
    if (carry > 0) {
        insert(start, carry);
    }
    return start;
}

int main() {
    node *s1, *s2, *s3;
    ;
    s1 = NULL, s2 = NULL;
    string n1, n2, n3;
    cout << "\nEnter the first number : ";
    cin >> n1;
    cout << "\nEnter the second number : ";
    cin >> n2;
    for (int i = 0; i < n1.length(); i++) {
        int d = n1[i] - '0';
        insert(s1, d);
    }
    for (int i = 0; i < n2.length(); i++) {
        int d = n2[i] - '0';
        insert(s2, d);
    }
    cout << n1 << '+' << n2 << '=';
    s3 = numberAdd(s1, s2);
    display(s3);
    return 0;
}