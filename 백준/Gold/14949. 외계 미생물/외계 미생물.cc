#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int h, w;
const int MOD = 1e9 + 7;

ll fact[401], invFact[401];

ll bpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2) {
            res = (res * base) % MOD;
        }
        exp >>= 1;
        base = (base * base) % MOD;
    }
    return res;
}

ll nCr(ll n, ll r) {
    return ((fact[n] * invFact[r]) % MOD) * invFact[n - r] % MOD;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 400; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    for (int i = 0; i <= 400; i++) {
        invFact[i] = bpow(fact[i], MOD - 2);
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;

    precompute();
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
    dp[0][1] = 1;

    for (int day = 1; day <= h; day++) {
        for (int i = 1; i <= w; i++) {
            if (dp[day - 1][i] == 0) continue;
            for (int j = 1; j <= w; j++) {
                dp[day][j] =
                    (dp[day][j] + (dp[day - 1][i] * nCr(i + j - 1, j))) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= w; i++) {
        ans = (ans + dp[h][i]) % MOD;
    }

    cout << ans << "\n";

    return 0;
}