#include <bits/stdc++.h>

using namespace std;

bool validate(string s) {
    stack<char> st;
    for (const auto &ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            if (ch == ')' && st.top() == '(') st.pop();
            else if (ch == '}' && st.top() == '{') st.pop();
            else if (ch == ']' && st.top() == '[') st.pop();
            else return false;
        }
    }

    return st.empty();
}

int solution(string s) {
    const int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (validate(s)) cnt++;
        char ch = s[0];
        s = s.substr(1, n - 1) + ch;
    }

    return cnt;
}
