#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, q, l, b, n, p;
    cin >> k >> q >> l >> b >> n >> p;

    cout << 1 - k << " " << 1 - q << " " << 2 - l << " " << 2 - b << " "
         << 2 - n << " " << 8 - p << "\n";

    return 0;
}
