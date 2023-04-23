#include <iostream>
using namespace std;
const int Size = 5;
struct deque {
    int arr[Size];
    int front, rear;
};
void insertion_at_front(deque *dq) {
    int x;
    if ((dq->front == 0 && dq->rear == Size - 1) ||
        (dq->rear + 1 == dq->front)) {
        cout << "Queue is Full\n";
    } else {
        if (dq->front == -1) {
            dq->rear = 0;
            dq->front = 0;
        } else {
            if (dq->front == 0) {
                dq->front = Size - 1;
            } else {
                dq->front = dq->front - 1;
            }
        }
        cout << "Enter the Element to be Inserted: ";
        cin >> x;
        dq->arr[dq->front] = x;
        cout << x << " is successfully Inserted\n";
    }
}

void insertion_at_rear(deque *dq) {
    int x;
    if ((dq->front == 0 && dq->rear == Size - 1) ||
        (dq->front == dq->rear + 1)) {
        cout << "Queue is Full\n";
    } else {
        if (dq->front == -1) {
            dq->rear = 0;
            dq->front = 0;
        } else {
            dq->rear = (dq->rear + 1) % Size;
        }
        cout << "Enter the Element to be Inserted: ";
        cin >> x;
        dq->arr[dq->rear] = x;
        cout << x << " is successfully Inserted\n";
    }
}

void deletion_from_front(deque *dq) {
    int x;
    if (dq->front == -1)
        cout << "Queue is Empty\n";
    else {
        x = dq->arr[dq->front];
        if (dq->front == dq->rear) {
            dq->front = -1;
            dq->rear = -1;
        } else {
            dq->front = (dq->front + 1) % Size;
        }
        cout << x << " is successfully Deleted\n";
    }
}
void deletion_from_end(deque *dq) {
    int x;
    if (dq->front == -1)
        cout << "Queue is Empty\n";
    else {
        x = dq->arr[dq->rear];
        if (dq->front == dq->rear) {
            dq->front = -1;
            dq->rear = -1;
        } else if (dq->rear == 0)
            dq->rear = Size - 1;
        else
            dq->rear--;
        cout << x << " is successfully Deleted\n";
    }
}

void display(deque *dq) {
    if (dq->front == -1)
        cout << "List is Empty\n";
    else {
        if (dq->front <= dq->rear) {
            for (int i = dq->front; i <= dq->rear; i++) {
                cout << dq->arr[i] << " ";
            }
            cout << "\n";
        } else {
            for (int i = dq->front; i < Size; i++) {
                cout << dq->arr[i] << " ";
            }
            for (int i = 0; i <= dq->rear; i++) {
                cout << dq->arr[i] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    deque dq;
    dq.front = -1, dq.rear = -1;
    int ch;
    while (1) {
        cout << "\n1. Insertion at rear";
        cout << "\n2. Insertion at front";
        cout << "\n3. Deletion from front";
        cout << "\n4. Deletion from end";
        cout << "\n5. Display";
        cout << "\n6. Exit ";
        cout << "\n Enter your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                insertion_at_rear(&dq);
                break;

            case 2:
                insertion_at_front(&dq);
                break;

            case 3:
                deletion_from_front(&dq);
                break;

            case 4:
                deletion_from_end(&dq);
                break;

            case 5:
                display(&dq);
                break;

            case 6:
                cout << "EXIT SUCCESSFULLY\n";
                exit(0);

            default:
                cout << "Enter the correct choice\n";
                break;
        }
    }
    return 0;
}
