#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    int n, k;
    cin >> n >> k;
    string num;
    cin >> num;

    stack<char> stk;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && stk.top() < num[i] && cnt < k) {
            stk.pop();
            cnt++;
        }

        stk.push(num[i]);
    }

    while (cnt < k) {
        stk.pop();
        cnt++;
    }

    string ans = "";
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());

    cout << ans << "\n";

    return 0;
}