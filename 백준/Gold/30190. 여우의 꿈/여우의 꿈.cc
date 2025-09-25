#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll f[MAX];

void init() {
    f[0] = 0;
    for (int i = 1; i < MAX; i++) {
        f[i] = (f[i - 1] * 2 + 1) % MOD;
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& i : a) cin >> i;

    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int src = k;
        int dst = a[i];
        if (src == dst) {
            continue;
        }

        ans = (ans + f[i] + 1) % MOD;
        k = 6 - src - dst;
    }

    cout << ans << "\n";

    return 0;
}
