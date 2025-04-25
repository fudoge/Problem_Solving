#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % MOD;
    }
    cout << dp[n] << "\n";
    return 0;
}