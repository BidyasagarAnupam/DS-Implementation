#include <bits/stdc++.h>
using namespace std;

// Function to perform arithmetic operations.
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a,b);
    }
}

void evaluation_infix(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            st.push(c - '0');
        } else {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            st.push((num1, num2, c));
           
        }
    }
    cout<<st.top()<<endl;
}

int main() {
    string exp = "-+2*34/1^23";
    reverse(exp.begin(), exp.end());
    evaluation_infix(exp);

    return 0;
}