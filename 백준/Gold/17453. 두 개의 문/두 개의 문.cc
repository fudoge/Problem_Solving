#include <bits/stdc++.h>

#include <sstream>

using namespace std;

int n, m;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string temp;
    cin >> temp;
    bitset<100> door, flip;
    for (int i = 0; i < n; i++) {
        door[i] = temp[i] - '0';
    }

    vector<bitset<100>> switches(m);
    for (int i = 0; i < m; i++) {
        cin >> temp;
        for (int j = 0; j < n; j++) {
            switches[i][j] = temp[j] - '0';
        }
    }

    vector<string> ans(2 * n + 1, "");
    int maxState = 1 << m;
    int lastGray = 0;
    for (int k = 0; k < maxState; k++) {
        int gray = k ^ (k >> 1);
        if (k == 0) {
            flip.reset();
        } else {
            int diff = gray ^ lastGray;
            int idx = __builtin_ctz(diff);
            flip ^= switches[idx];
        }
        lastGray = gray;

        int ones = (door ^ flip).count();
        int sum = 2 * ones - n;

        int cnt = __builtin_popcount(gray);
        ostringstream oss;
        oss << cnt;
        for (int i = 0; i < m; i++) {
            if (gray & (1 << i)) oss << " " << (i + 1);
        }
        ans[sum + n] = oss.str();
    }

    for (const auto &str : ans) {
        cout << (str.empty() ? "-1" : str) << "\n";
    }

    return 0;
}