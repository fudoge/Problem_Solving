#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &i : a) cin >> i;

    sort(a.begin(), a.end());

    ll ans = LLONG_MIN;
    for (int median = 1; median < n - 1; median++) {
        int minleft = 0;
        int minright = median + 1;
        ll minSum = abs(a[minleft] + a[minright] - 2 * a[median]);

        int maxleft = median - 1;
        int maxright = n - 1;
        ll maxSum = abs(a[maxleft] + a[maxright] - 2 * a[median]);

        ans = max({ans, minSum, maxSum});
    }

    cout << ans << "\n";

    return 0;
}