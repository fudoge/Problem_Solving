#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    if (k == 1 && n != 1 && m == 1) {
        cout << "-1\n";
        return;
    }

    int move = 0;
    while (true) {
        n -= m * k;
        move++;
        if (n <= 0) break;
        n += 1;
        move++;
    }
    cout << move << "\n";
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
