#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a;
    while ((cin >> a) && a != 0) {
        ll ans = 0;

        ll aSquared = a * a;

        for (ll x = 1; x < a; x++) {
            if (aSquared % x == 0) {
                ll y = aSquared / x;

                if ((y - x) % 2 == 0) {
                    ll b = (y - x) / 2;

                    if (b > a) ans++;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
