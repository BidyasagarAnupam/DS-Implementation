#include<bits/stdc++.h>
using namespace std;

string postToPre(string s) {
    stack<string> st;
    for(int i=0; i<s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z')) {
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string temp = s[i] + op2 + op1;
            st.push(temp); 
        }
    }
    string ans = "";
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string postfix = "ABC/-AK/L-*";
    cout << "Prefix : " << postToPre(postfix);
    return 0;
}