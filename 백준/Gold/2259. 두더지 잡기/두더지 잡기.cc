#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128_t;

struct Node {
    ll x;
    ll y;
    ll t;
};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, s;
    cin >> n >> s;
    ll s2 = s * s;

    vector<Node> d(n + 1);
    d[0].x = 0;
    d[0].y = 0;
    d[0].t = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i].x >> d[i].y >> d[i].t;
    }

    sort(d.begin(), d.end(),
         [](const auto &a, const auto &b) { return a.t < b.t; });

    vector<int> dp(n + 1);
    dp[0] = 0;
    int ans = dp[0];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            ll dx = d[i].x - d[j].x;
            ll dy = d[i].y - d[j].y;
            ll dt = d[i].t - d[j].t;

            i128 dist2 = (i128)dx * dx + (i128)dy * dy;
            i128 reach = (i128)s * dt;
            if (dist2 <= reach * reach && (j == 0 || dp[j] > 0)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}
