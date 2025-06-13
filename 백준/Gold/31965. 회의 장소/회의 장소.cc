#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll getCost(int idx, int l, int r, vector<ll> &a, vector<ll> &pref) {
    ll leftCnt = idx - l;
    ll leftSum = pref[idx] - pref[l];
    ll rightCnt = r - idx;
    ll rightSum = pref[r + 1] - pref[idx + 1];

    return a[idx] * leftCnt - leftSum + rightSum - a[idx] * rightCnt;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n), pref(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = a[i] + pref[i];
    }

    while (q--) {
        ll L, R;
        cin >> L >> R;

        int l = lower_bound(a.begin(), a.end(), L) - a.begin();
        int r = upper_bound(a.begin(), a.end(), R) - a.begin() - 1;

        if (l >= r) {
            cout << "0\n";
            continue;
        }

        int m = (l + r) >> 1;
        ll lCost = getCost(l, l, r, a, pref);
        ll rCost = getCost(r, l, r, a, pref);
        ll mCost = getCost(m, l, r, a, pref);

        cout << max(lCost, rCost) - mCost << "\n";
    }

    return 0;
}