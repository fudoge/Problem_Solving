#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll bpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) {
            res = res * base;
        }
        exp >>= 1;
        base = base * base;
    }

    return res;
}

void solve() {
    ll c;
    cin >> c;

    vector<int> ans;

    ll i = 2;
    while (c > 0 && i * i <= c) {
        ll cnt = 0;
        while (c % i == 0) {
            cnt++;
            c /= i;
        }
        if (cnt == 0) {
            i++;
            continue;
        }
        int shift = 0;
        while (cnt) {
            if (cnt & 1) {
                ans.emplace_back(bpow(i, 1 << shift));
            }
            cnt >>= 1;
            shift++;
        }
        i++;
    }
    if (c > 1) {
        ans.emplace_back(c);
    }
    sort(ans.begin(), ans.end());

    for (const auto &elem : ans) {
        cout << elem << " ";
    }
    cout << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}