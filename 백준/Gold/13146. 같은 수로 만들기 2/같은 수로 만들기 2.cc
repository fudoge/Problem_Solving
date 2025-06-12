#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;

    ll ans = 0;
    vector<ll> stk;
    for (int i = 0; i < n; i++) {
        ll minElem = LLONG_MAX;
        while (!stk.empty() && stk.back() < a[i]) {
            minElem = min(minElem, stk.back());
            stk.pop_back();
        }
        if (minElem != LLONG_MAX) {
            ans += a[i] - minElem;
        }
        stk.emplace_back(a[i]);
    }

    ans += stk[0] - stk.back();

    cout << ans << "\n";
    return 0;
}