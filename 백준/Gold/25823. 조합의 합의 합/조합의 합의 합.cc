#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll MAX = 400001;

ll fact[MAX] = {0};
ll invfact[MAX] = {0};

ll bpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

ll nCr(ll n, ll r) {
    return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}
int main(int argc, char *argv[]) {
    int m;
    cin >> m;

    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    invfact[MAX - 1] = bpow(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--) {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }

    ll ans = 0;
    for (int n = 3; n <= m; n++) {
        ans = (ans + nCr(2 * n, n)) % MOD;
    }

    cout << ans << "\n";
    return 0;
}