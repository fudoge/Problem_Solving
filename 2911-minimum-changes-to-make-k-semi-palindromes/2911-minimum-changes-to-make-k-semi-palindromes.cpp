#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> diag(n+1, vector<int>(n+1));
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                diag[i][j] = (s[i] != s[j]) + diag[i+1][j+1];
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, INF)), f(n, vector<int>(n, 0));
        for(int d = 1; d * 2 <= n; d++) {
            for(int len = 2*d; len <= n; len += d) {
                for(int l = 0; l + len <= n; l++) {
                    int r = l + len - 1;

                    int val = diag[l][r-d+1] - diag[l+d][r+1];

                    if(len >= 4 * d) {
                        val += f[l+d][r-d];
                    }

                    f[l][r] = val;
                    cost[l][r] = min(cost[l][r], val);
                }
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(k+1, INF));
        dp[0][0] = 0;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                if(i < 2 * j) continue;
                for(int prev = 2*(j-1); prev <= i-2; prev++) {
                    dp[i][j] = min(dp[i][j], dp[prev][j-1] + cost[prev][i-1]);
                }
            }
        }

        return dp[n][k];
    }
};