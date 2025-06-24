#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ll n;
    cin >> n;

    ll x = 1, y = 1;
    while (true) {
        if ((x + 1) * (y + 1) >= n) {
            cout << 2 * (x + y) << "\n";
            break;
        }
        x++;
        if ((x + 1) * (y + 1) >= n) {
            cout << 2 * (x + y) << "\n";
            break;
        }
        y++;
    }

    return 0;
}
