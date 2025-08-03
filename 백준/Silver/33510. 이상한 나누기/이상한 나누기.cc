#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = n - 1; i > 0; i--) {
        if (s[i] == '1') {
            while (i > 0 && s[i] == '1') i--;
            s[i] = '1';
            i++;
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
