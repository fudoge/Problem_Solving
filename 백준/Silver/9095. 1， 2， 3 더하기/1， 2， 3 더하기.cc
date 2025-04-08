#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; i++) {
        if (i - 1 >= 0) dp[i] += dp[i - 1];
        if (i - 2 >= 0) dp[i] += dp[i - 2];
        if (i - 3 >= 0) dp[i] += dp[i - 3];
    }

    cout << dp[n] << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}