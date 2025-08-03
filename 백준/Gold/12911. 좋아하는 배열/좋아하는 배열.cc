#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
    ll last_sum = 0;

    for (int j = 1; j <= k; j++) dp[1][j] = 1;
    last_sum = k;

    for (int i = 2; i <= n; i++) {
        ll sum = 0;
        for (int j = 1; j <= k; j++) {
            dp[i][j] = last_sum;

            for (int x = 2 * j; x <= k; x += j) {
                dp[i][j] = (dp[i][j] - dp[i - 1][x]) % MOD;
            }
            dp[i][j] = (dp[i][j] + MOD) % MOD;
            sum = (sum + dp[i][j]) % MOD;
        }
        last_sum = sum;
    }

    cout << last_sum << "\n";

    return 0;
}
