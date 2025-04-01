#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

pll normalize(ll x, ll y) {
    if (x == 0 && y == 0) return {0, 0};
    ll g = gcd(llabs(x), llabs(y));
    x /= g;
    y /= g;
    return {x, y};
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    pll main_dir = {0, 0};
    ll dmg = 0;

    vector<ll> nums;

    for (int i = 0; i < n; i++) {
        ll x, y, d;
        cin >> x >> y >> d;

        auto dir = normalize(x, y);
        if (main_dir.first == 0 && main_dir.second == 0) main_dir = dir;
        nums.emplace_back(d);
    }
    sort(nums.begin(), nums.end());

    int last_ans = nums.size();
    for (int i = 0; i < m; i++) {
        ll x, y, d;
        cin >> x >> y >> d;

        auto dir = normalize(x, y);
        if (dir != main_dir) {
            cout << last_ans << "\n";
            continue;
        }

        dmg += d;
        int ub = upper_bound(nums.begin(), nums.end(), dmg) - nums.begin();
        cout << nums.size() - ub << "\n";
        last_ans = nums.size() - ub;
    }

    return 0;
}