#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int n, k;
        cin >> n >> k;

        if (n == 0 && k == 0) break;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        vector<vector<ll>> dp(n, vector<ll>(k + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][1] = 1;
        }

        for (int j = 2; j <= k; j++) {
            for (int i = 0; i < n; i++) {
                for (int t = 0; t < i; t++) {
                    if (a[t] < a[i]) {
                        dp[i][j] += dp[t][j - 1];
                    }
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dp[i][k];
        }

        cout << ans << "\n";
    }

    return 0;
}
