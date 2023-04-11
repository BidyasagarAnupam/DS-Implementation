#include <bits/stdc++.h>
using namespace std;
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void infix_to_postfix(string exp) {
    stack<char> st;
    string res;
    for (int i = 0; i < exp.size(); i++) {
        char c = exp[i];
        if (c == '(') {
            st.push('(');
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                   (c >= '0' && c <= '9')) {
            res += c;
        } else if (c == ')') {
            while (st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(c) <= prec(st.top()) &&
                   !(c == '^' && st.top() == '^')) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    cout << res << endl;
}

int main() {
    string exp = "k+l-m*n+(o^p)*w/u/v*t+q^j^a";
    infix_to_postfix(exp);
    return 0;
}