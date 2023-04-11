#include <bits/stdc++.h>
using namespace std;


string preToInfix(string pre) {
    stack<string> s;
    int length = pre.size();
    for (int i = length - 1; i >= 0; i--) {
        if ((pre[i] >= 'a' && pre[i] <= 'z') || (pre[i] >= 'A' && pre[i] <= 'Z')) {
            s.push(string(1, pre[i]));
        } else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = "(" + op1 + pre[i] + op2 + ")";
            s.push(temp);
        }
    }
    return s.top();
}

int main() {
  string pre_exp = "*-A/BC-/AKL";
  cout << "Infix : " << preToInfix(pre_exp);
  return 0;
}