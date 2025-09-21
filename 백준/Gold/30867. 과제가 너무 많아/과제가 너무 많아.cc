#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, n;
    string s;
    cin >> l >> n >> s;

    int wStreak = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == 'h') {
            int lastW = i - wStreak;
            swap(s[i], s[lastW]);
        } else if (s[i] == 'w') {
            wStreak = min(wStreak + 1, n);
        } else {
            wStreak = 0;
        }
    }

    cout << s << "\n";

    return 0;
}
