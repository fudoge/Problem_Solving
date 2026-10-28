#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

constexpr int MAXK = 1024;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(MAXK, 0)));

        dp[0][0][grid[0][0]] = 1;
        int x = grid[0][0];
        for(int i = 1; i < m; i++) {
            int next = x ^ grid[i][0];
            dp[i][0][next] |= 1;
            x = next;
        }

        x = grid[0][0];
        for(int j = 1; j < n; j++) {
            int next = x ^ grid[0][j];
            dp[0][j][next] |= 1;
            x = next;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                for(int k = 0; k < MAXK; k++) {
                    if(dp[i-1][j][k]) {
                        int fromLeft = k ^ grid[i][j];
                        dp[i][j][fromLeft] |= 1;
                    }
                    if(dp[i][j-1][k]) {
                        int fromTop = k ^ grid[i][j];
                        dp[i][j][fromTop] |= 1;
                    }
                }
            }
        }

        for(int k = 0; k < MAXK; k++) {
            if(dp[m-1][n-1][k]) return k;
        }

        return -1;
    }
};