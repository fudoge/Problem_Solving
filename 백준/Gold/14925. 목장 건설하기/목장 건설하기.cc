#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int ans = 0;
    vector<int> hist(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                hist[j]++;
            } else {
                hist[j] = 0;
            }
        }
        stack<int> stk;
        auto hhist = hist;
        hhist.emplace_back(0);
        for (int j = 0; j <= n; j++) {
            while (!stk.empty() && hhist[stk.top()] > hhist[j]) {
                int h = hist[stk.top()];
                stk.pop();
                int w = stk.empty() ? j : j - stk.top() - 1;
                ans = max(ans, min(h, w));
            }
            stk.emplace(j);
        }
    }

    cout << ans << "\n";

    return 0;
}