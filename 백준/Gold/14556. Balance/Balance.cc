#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 9;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll ans = 1;
    for (int i = 1; i < 2 * n; i += 2) {
        ans *= i;
        ans %= MOD;
    }

    cout << ans << "\n";

    return 0;
}