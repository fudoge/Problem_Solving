#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<int>> mat(n, vector<int>(m, 0));
    vector<pii> checkpoints;

    for (int i = 0; i < a; i++) {
        int r, c;
        cin >> r >> c;
        checkpoints.emplace_back(r - 1, c - 1);
    }
    checkpoints.emplace_back(0, 0);
    checkpoints.emplace_back(n - 1, m - 1);
    sort(checkpoints.begin(), checkpoints.end());

    for (int i = 0; i < b; i++) {
        int r, c;
        cin >> r >> c;
        mat[r - 1][c - 1] = 1;
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = (mat[0][0] == 0 ? 1 : 0);

    for (int k = 1; k < checkpoints.size(); ++k) {
        int prevR = checkpoints[k - 1].first;
        int prevC = checkpoints[k - 1].second;
        int nextR = checkpoints[k].first;
        int nextC = checkpoints[k].second;

        vector<vector<int>> temp(n, vector<int>(m, 0));
        if (mat[prevR][prevC] == 0) temp[prevR][prevC] = dp[prevR][prevC];

        for (int i = prevR; i <= nextR; ++i) {
            for (int j = prevC; j <= nextC; ++j) {
                if (mat[i][j] == 1 || (i == prevR && j == prevC)) continue;
                if (i > prevR) temp[i][j] += temp[i - 1][j];
                if (j > prevC) temp[i][j] += temp[i][j - 1];
            }
        }

        for (int i = prevR; i <= nextR; ++i)
            for (int j = prevC; j <= nextC; ++j) dp[i][j] = temp[i][j];
    }

    cout << dp[n - 1][m - 1] << "\n";
    return 0;
}