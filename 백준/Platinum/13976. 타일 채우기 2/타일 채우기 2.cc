#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
const ll MOD = 1e9 + 7;
vvll mul(vvll &a, vvll &b) {
    vvll res(4, vll(4));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
    return res;
}
vvll power(vvll base, ll exp) {
    vvll res(4, vll(4));
    for (int i = 0; i < 4; i++) res[i][i] = 1;

    while (exp) {
        if (exp % 2) res = mul(res, base);
        base = mul(base, base);
        exp >>= 1;
    }

    return res;
}
int main(int argc, char *argv[]) {
    ll n;
    cin >> n;
    if (n % 2) {
        cout << "0\n";
        return 0;
    }

    n /= 2;
    if (n == 0) {
        cout << "1\n";
        return 0;
    }
    if (n == 1) {
        cout << "3\n";
        return 0;
    }
    if (n == 2) {
        cout << "11\n";
        return 0;
    }
    vvll mat = {{4, MOD - 1, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
    auto res = power(mat, n - 2);

    vll base = {11, 3, 1, 0};
    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        ans = (ans + res[0][i] * base[i] % MOD) % MOD;
    }
    cout << ans << "\n";

    return 0;
}