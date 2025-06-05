#include <bits/stdc++.h>

using namespace std;
int a[2], b[2], c[2];

int calc() {
    int res = INT_MAX;

    res = min(res, max({a[0], b[0], c[0]}) * (a[1] + b[1] + c[1]));
    res = min(res, max({a[0] + b[0], c[0]}) * (max(a[1], b[1]) + c[1]));
    res = min(res, max({b[0] + c[0], a[0]}) * (max(b[1], c[1]) + a[1]));
    res = min(res, max({c[0] + a[0], b[0]}) * (max(c[1], a[1]) + b[1]));

    return res;
}

void solve() {
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];

    int ans = INT_MAX;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (i) swap(a[0], a[1]);
                if (j) swap(b[0], b[1]);
                if (k) swap(c[0], c[1]);

                ans = min(ans, calc());

                if (i) swap(a[0], a[1]);
                if (j) swap(b[0], b[1]);
                if (k) swap(c[0], c[1]);
            }
        }
    }

    cout << ans << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}