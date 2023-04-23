#include <iostream>
using namespace std;
int MAX = 10;
int stack[10];
int top1 = -1, top2 = MAX;

//  function for push()
void push(int x) {
    int ch;
    if (top1 == top2 - 1) {
        cout << "Stack Overflow";
    } else {
        cout << "\n Type 1 to push the elements in stack A \n Type 2 to push "
                "the elements in stack B\n";
        cin >> ch;
        if (ch == 1) {
            stack[++top1] = x;
        } else {
            stack[--top2] = x;
        }
        cout << x << " is pushed successfully" << endl;
    }  // End of push()
}

//  pop()
void pop() {
    int x, ch;
    cout << "\n Type 1 to pop the elements in stack A \n Type 2 to pop the "
            "elements in stack B\n";
    cin >> ch;
    if (ch == 1) {
        if (top1 == -1)
            cout << "Stack is empty\n";
        else {
            x = stack[top1--];
        }
    } else {
        if (top2 == 10) {
            cout << "\n Stack is empty\n";
        } else {
            x = stack[top2++];
            cout << x << " is successfully popped\n";
        }
    }
}  // pop end

//  display
void display() {
    int i;
    if (top1 == -1) {
        cout << "\n Stack A is empty";
    } else {
        cout << "\n Elements of stack A are\n";
        for (int i = top1; i >= 0; i--) {
            cout << stack[i] << " ";
        }
    }
    if (top2 == MAX) {
        cout << "Stack B is empty \n";
    } else {
        cout << "\n Element of stack B are \n";
        for (int i = top2; i < MAX; i++) {
            cout << stack[i] << " ";
        }
    }
}

int main() {
    int option;
    do {
        cout << "\n1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your chooice: ";
        cin >> option;
        switch (option) {
            case 1:
                int x;
                cout << "Enter the number to be insert: ";
                cin >> x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exit....\n";
                exit(0);
        }
    } while (option != 4);

    return 0;
}
