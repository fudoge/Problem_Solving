#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    string str, pat;
    cin >> str >> pat;

    stack<char> stk;
    for (int i = 0; i < str.size(); i++) {
        stk.push(str[i]);
        if (stk.size() >= pat.size() && stk.top() == pat.back()) {
            bool flag = true;
            stack<char> temp;
            for (int j = pat.size() - 1; j >= 0; j--) {
                if (stk.top() != pat[j]) {
                    flag = false;
                    break;
                }
                temp.emplace(stk.top());
                stk.pop();
            }
            if (!flag) {
                while (!temp.empty()) {
                    stk.emplace(temp.top());
                    temp.pop();
                }
            }
        }
    }

    string ans;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    for(int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}