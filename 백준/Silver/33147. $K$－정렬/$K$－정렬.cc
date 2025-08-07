#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int g = gcd(n, k);
    vector<vector<int>> arrs(g);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arrs[(i % g)].emplace_back(x);
    }

    for (int i = 0; i < g; i++) {
        sort(arrs[i].begin(), arrs[i].end());
    }

    int circle = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (i != arrs[i % g][circle]) {
            cout << "NO\n";
            return 0;
        }
        t++;
        if (t >= g) {
            t = 0;
            circle++;
        }
    }

    cout << "YES\n";

    return 0;
}
