#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int coeff, power;
    Node *next;
    Node(int co, int pow) {
        coeff = co;
        power = pow;
        this->next = NULL;
    }
};

void insert(Node *head, int coeff, int power) {
    Node *new1 = new Node(coeff, power);
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = new1;
}

void print(Node *head) {
    cout << "Polynomial\n";
    while (head != NULL) {
        cout << head->coeff << "x^" << head->power << " ";
        head = head->next;
    }
}

void addPoly(Node *head1, Node *head2) {
    if (head1 == NULL && head2 == NULL) {
        return;
    } else if (head1->power == head2->power) {
        cout << head1->coeff + head2->coeff << "x^" << head1->power<<" ";
        addPoly(head1->next, head2->next);
    } else if (head1->power > head2->power) {
        cout << head1->coeff << "x^" << head1->power<<" ";
        addPoly(head1->next, head2);
    } else {
        cout << head2->coeff << "x^" << head2->power<<" ";
        addPoly(head1, head2->next);
    }
}
int main() {
    Node *head1 = new Node(5, 3);
    insert(head1, 3, 1);
    Node *head2 = new Node(2, 3);
    insert(head2, 3, 2);
    insert(head2, 7, 1);
    print(head1);
    cout << endl;
    print(head2);
    cout << endl;
    cout << "Addition\n";
    addPoly(head1, head2);
    return 0;
}