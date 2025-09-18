#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    sort(a.begin(), a.end());
    ll ans = 1e18;
    for (int i = 1; i < n; i++) {
        ll left = a[0] * (i);
        ll right = a[i] * (n - i);
        ll productivity = left + right;

        ll time = (k - 1 + productivity) / productivity;
        if (time < ans) {
            ans = time;
        }
    }

    cout << ans << "\n";

    return 0;
}
