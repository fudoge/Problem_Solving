#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;
        cout << n / c + ((n % c) > 0 ? 1 : 0) << "\n";
    }

    return 0;
}