#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    set<int> s;
    ll ans = 1e18;
    ll dist = 0;

    auto add = [&](int x) {
        auto it = s.insert(x).first;
        if (it != s.begin()) {
            dist += llabs((ll)pos[*it] - pos[*prev(it)]);
        }
        auto itn = next(it);
        if (itn != s.end()) {
            dist += llabs((ll)pos[*it] - pos[*itn]);
        }
        if (it != s.begin() && itn != s.end()) {
            dist -= llabs((ll)pos[*itn] - pos[*prev(it)]);
        }
    };

    auto remove = [&](int x) {
        auto it = s.find(x);
        auto itn = next(it);
        if (it != s.begin()) {
            dist -= llabs((ll)pos[*it] - pos[*prev(it)]);
        }
        if (itn != s.end()) {
            dist -= llabs((ll)pos[*it] - pos[*itn]);
        }
        if (it != s.begin() && itn != s.end()) {
            dist += llabs((ll)pos[*itn] - pos[*prev(it)]);
        }
        s.erase(it);
    };

    for (int i = 1; i <= n; ++i) {
        add(a[i]);
        if (s.size() > k) remove(a[i - k]);
        if (s.size() == k) ans = min(ans, dist);
    }
    cout << ans << "\n";

    return 0;
}
