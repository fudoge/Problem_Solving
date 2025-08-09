#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> pos_intercepts;
    vector<ll> neg_intercepts;
    vector<ll> b_intercepts;

    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        pos_intercepts.emplace_back(a - b);
        neg_intercepts.emplace_back(a + b);

        b_intercepts.emplace_back(a - b);
        b_intercepts.emplace_back(a + b);
    }

    sort(pos_intercepts.begin(), pos_intercepts.end());
    sort(neg_intercepts.begin(), neg_intercepts.end());
    pos_intercepts.erase(unique(pos_intercepts.begin(), pos_intercepts.end()),
                         pos_intercepts.end());
    neg_intercepts.erase(unique(neg_intercepts.begin(), neg_intercepts.end()),
                         neg_intercepts.end());

    ll ans = 0;
    for (int i = 0; i < pos_intercepts.size(); i++) {
        ll intercept = pos_intercepts[i];

        ll idx = upper_bound(neg_intercepts.begin(), neg_intercepts.end(),
                             intercept - 1) -
                 neg_intercepts.begin();

        ans += neg_intercepts.size() - idx;
    }

    ll i = 0, j = 0, inter = 0;
    while (i < pos_intercepts.size() && j < neg_intercepts.size()) {
        if (pos_intercepts[i] == neg_intercepts[j]) {
            inter++;
            i++;
            j++;
        } else if (pos_intercepts[i] < neg_intercepts[j])
            i++;
        else
            j++;
    }
    ans += pos_intercepts.size() + neg_intercepts.size() - 2 * inter;

    cout << ans << "\n";

    return 0;
}
