#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a, b, c, d, k;

ll get_toka_dist(ll t) {
    if (k == 0) return b * t;
    ll max_mov = (b + k - 1) / k;
    if (t <= max_mov) {
        return t * (2 * b - (t - 1) * k) / 2;
    }
    return max_mov * (2 * b - (max_mov - 1) * k) / 2;
}

int main(int argc, char *argv[]) {
    cin >> a >> b >> c >> d >> k;

    ll lo = 1, hi = 1e12;
    ll toka_time = LLONG_MAX;
    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;

        ll toka_dist = get_toka_dist(mid);
        if (toka_dist >= a) {
            toka_time = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    if (toka_time == LLONG_MAX) {
        cout << "-1\n";
        return 0;
    }

    if (c == 0 && toka_time > 1 && b > d) {
        cout << toka_time << "\n";
        return 0;
    }

    ll doldol_dist = toka_time * d;
    if (doldol_dist >= a + c) {
        cout << "-1\n";
        return 0;
    }

    cout << toka_time << "\n";

    return 0;
}
