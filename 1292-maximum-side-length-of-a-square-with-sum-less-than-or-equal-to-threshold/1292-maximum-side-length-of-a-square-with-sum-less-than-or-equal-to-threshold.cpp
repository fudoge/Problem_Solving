#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        dp[0][0] = mat[0][0];
        for(int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + mat[i][0];
        }
        for(int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + mat[0][j];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = mat[i][j] +  dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int limit = min(i, j) + 1;
                for(int k = ans+1; k <= limit; k++) {
                    int sum = dp[i][j];
                    if(i-k >= 0 && j-k >= 0) {
                        sum -= dp[i-k][j];
                        sum -= dp[i][j-k];
                        sum += dp[i-k][j-k];
                    } else if(i-k >= 0) {
                        sum -= dp[i-k][j];
                    } else if(j-k >= 0) {
                        sum -= dp[i][j-k];
                    }
                    if(sum <= threshold) {
                        ans = k;
                    }
                }
            }
        }
        return ans;
    }
};