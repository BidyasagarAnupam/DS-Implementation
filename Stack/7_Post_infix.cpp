#include <bits/stdc++.h>
using namespace std;

string postToInfix(string post) {
    stack<string> s;
    int length = post.size();
    for (int i = 0; i <= length - 1; i++) {
        if ((post[i] >= 'a' && post[i] <= 'z') ||
            (post[i] >= 'A' && post[i] <= 'Z')) {
            s.push(string(1, post[i]));
        } else {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();

            string temp = "(" + op1 + post[i] + op2 + ")";
            s.push(temp);
        }
    }
    return s.top();
}

int main() {
    string post_exp = "ab*c+";
    cout << "Infix : " << postToInfix(post_exp);
    return 0;
}