#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        int m;
        cin >> m;

        int ans = 0;
        int curr = 0;
        for (int i = 0; i < m; i++) {
            int p1, p2;
            cin >> p1 >> p2;

            curr += p1 - p2;
            ans = min(ans, curr);
        }

        cout << -ans << "\n";
    }

    return 0;
}