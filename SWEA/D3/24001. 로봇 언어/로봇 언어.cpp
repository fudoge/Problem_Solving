#include <bits/stdc++.h>

using namespace std;
void solve() {
    string s;
    cin >> s;

    int ans = 0;
    int pos1 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L' || s[i] == '?')
            pos1--;
        else
            pos1++;
        ans = max(ans, abs(pos1));
    }
    int pos2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R' || s[i] == '?')
            pos2--;
        else
            pos2++;
        ans = max(ans, abs(pos2));
    }

    cout << ans << "\n";
}
int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}