#include <bits/stdc++.h>

using namespace std;

vector<int> z(string& s) {
    int n = s.size();
    vector<int> Z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            Z[i] = min(r - i + 1, Z[i - l]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    string r = s;
    reverse(r.begin(), r.end());
    int n = s.size();

    auto Z = z(r);
    Z[0] = n;

    int m;
    cin >> m;
    while (m--) {
        int i;
        cin >> i;
        cout << min(Z[n - i], i) << "\n";
    }

    return 0;
}
