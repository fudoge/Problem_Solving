#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    // C는 되도록 열려고 해라
    // U는 되도록 닫으려 해라
    int stk = 0;
    int ans = 0;
    string anss = "";
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == 'U') {
            if (stk == 0) {
                stk++;
                anss += '(';
            } else {
                stk--;
                anss += ')';
            }
            ans++;
        } else {
            if (stk == s.size() - i) {
                stk--;
                ans += 2;
                anss += ')';
            } else {
                stk++;
                anss += '(';
            }
        }
    }

    cout << ans << "\n";
    cout << anss << "\n";
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
