#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
   public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int prev = 0; prev < k; prev++) {
                    int curr = (prev + grid[i][j]) % k;
                    if (i - 1 >= 0) {
                        dp[i][j][curr] =
                            ((ll)dp[i][j][curr] + dp[i - 1][j][prev]) % MOD;
                    }
                    if (j - 1 >= 0) {
                        dp[i][j][curr] =
                            ((ll)dp[i][j][curr] + dp[i][j - 1][prev]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};