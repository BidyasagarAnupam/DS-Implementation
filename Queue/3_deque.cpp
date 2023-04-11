#include <bits/stdc++.h>
using namespace std;
const int size = 5;

struct deQue {
    int arr[size];
    int front;
    int rare;
};

void insert_rare_end(deQue *dq) {
    int item;
    if (dq->front == 0 && dq->rare == size - 1 || (dq->front == dq->rare + 1)) {
        cout << "Deque is overflow\n";
    } else {
        if (dq->front == -1) {
            dq->front = 0;
            dq->rare = 0;
        } else {
            dq->rare = (dq->rare + 1) % size;
        }
        cout << "Enter the element to be inserted: ";
        cin >> item;
        dq->arr[dq->rare] = item;
    }
}

void insert_front_end(deQue *dq) {
    int item;
    if (dq->front == 0 && dq->rare == size - 1 || (dq->front == dq->rare + 1)) {
        cout << "Deque is overflow\n";
    } else {
        if (dq->front == -1) {
            dq->front = 0;
            dq->rare = 0;
        } else {
            if (dq->front == 0) {
                dq->front = size - 1;
            } else {
                dq->front = (dq->front - 1);
            }
        }
        cout << "Enter the element to be inserted: ";
        cin >> item;
        dq->arr[dq->front] = item;
    }
}

void delete_rare_end(deQue *dq) {
    if (dq->front == -1) {
        cout << "Deque is empty\n";
    } else {
        cout << "Element " << dq->arr[dq->rare] << " is deleted\n";
        if (dq->rare == dq->front) {
            dq->front = -1;
            dq->rare = -1;
        } else {
            dq->rare = (dq->rare - 1) % size;
        }
    }
}

void delete_front_end(deQue *dq) {
    if (dq->front == -1) {
        cout << "Deque is empty\n";
    } else {
        cout << "Element " << dq->arr[dq->front] << " is deleted\n";
        if (dq->rare == dq->front) {
            dq->front = -1;
            dq->rare = -1;
        } else {
            dq->front = (dq->front + 1) % size;
        }
    }
}

void display(deQue *dq) {
    if (dq->front == -1) {
        cout << "Deque is empty\n";
    } else {
        if (dq->front <= dq->rare) {
            for (int i = dq->front; i <= dq->rare; i++) {
                cout << dq->arr[i] << " ";
            }
        } else {
            for (int i = dq->front; i < size; i++) cout << dq->arr[i] << " ";
            for (int i = 0; i <= dq->rare; i++) cout << dq->arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    deQue dq;
    dq.rare = -1;
    dq.front = -1;

    int ch;
    while (1) {
        cout << "1. insert front\n";
        cout << "2. insert rare\n";
        cout << "3. delete front\n";
        cout << "4. delete rare\n";
        cout << "5. disaply\n";
        cout << "6. exit\n";
        cout << "Enter : ";
        cin >> ch;
        switch (ch) {
            case 1:
                insert_front_end(&dq);
                break;
            case 2:
                insert_rare_end(&dq);
                break;
            case 3:
                delete_front_end(&dq);
                break;
            case 4:
                delete_rare_end(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                exit(0);

            default:
                break;
        }
    }
    return 0;
}