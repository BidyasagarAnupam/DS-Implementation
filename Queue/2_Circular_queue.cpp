#include <bits/stdc++.h>
using namespace std;
const int size = 5;
struct cq {
    int arr[size];
    int front, rare;
};

void insertion(cq *q, int x) {
    if ((q->front == 0 && q->rare == size - 1) ||
        (q->rare + 1) % size == q->front) {
        cout << "Queue is full\n";
    } else {
        if (q->front == -1) {
            q->front = 0;
            q->rare = 0;
        } else {
            q->rare = (q->rare + 1) % size;
        }
        q->arr[q->rare] = x;
        cout << x << " inserted...\n";
    }
}
void deletion(cq *q) {
    int x;
    if (q->front == -1) {
        cout << "Queue is empty\n";
    } else {
        x = q->arr[q->front];
        if (q->front == q->rare) {
            q->front = -1;
            q->rare = -1;
        } else {
            q->front = (q->front + 1) % size;
        }
        cout << x << " deleted...\n";
    }
}

void display(cq *q) {
    if (q->front == -1) {
        cout << "Queue is underflow";
    } else {
        if (q->front <= q->rare) {
            for (int i = q->front; i <= q->rare; i++) {
                cout << q->arr[i] << " ";
            }
        } else {
            for (int i = q->front; i < size; i++) {
                cout << q->arr[i] << " ";
            }
            for (int i = 0; i <= q->rare; i++) {
                cout << q->arr[i] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    cq q;
    q.front = -1;
    q.rare = -1;
    insertion(&q, 5);
    insertion(&q, 6);
    insertion(&q, 7);
    insertion(&q, 8);
    insertion(&q, 9);
    display(&q);
    deletion(&q);
    insertion(&q, 10);
    display(&q);


    return 0;
}