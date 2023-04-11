#include <bits/stdc++.h>
using namespace std;
const int size = 10;

struct lq {
    int arr[size];
    int rear, front;
};

void insert(lq *q, int x) {
    if (q->rear == size - 1)
        cout << "Queue is overflow\n";
    else {
        if (q->front == -1) {
            q->front = 0;
            q->rear = 0;
        } else {
            q->rear++;
        }
        q->arr[q->rear] = x;
    }
}

void deletion(lq *q) {
    int x;
    if (q->front == -1) {
        cout << "Queue is empty\n";
    } else {
        x = q->arr[q->front];
        cout << x << " is deleted....\n";
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
}

void display(lq *q) {
    if (q->front == -1) {
        cout << "Queue is empty\n";
    } else if (q->front <= q->rear) {
        for (int i = q->front; i <= q->rear; i++) {
            cout << q->arr[i] << "->";
        }
        cout<<"NULL\n";
    }
}

int main() {
    lq q;
    q.front = -1;
    q.rear = -1;
    insert(&q, 5);
    insert(&q, 6);
    insert(&q, 7);
    display(&q);
    deletion(&q);
    display(&q);
    return 0;
}