class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m1 = 1e9;
        int m2 = 1e9;
        int idx1 = 0, idx2;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
            if(dp[0][i] < m1) {
                idx2 = idx1;
                idx1 = i;
                m2 = m1;
                m1 = dp[0][i];
            } else if(dp[0][i] <= m2) {
                idx2 = i;
                m2 = dp[0][i];
            }
            // cout << dp[0][i] << " ";
        }
        // cout << idx1 << "|" << idx2 << "\n";

        for(int i = 1; i < n; i++) {
            int nextidx1 = 0, nextidx2;
            m1 = 1e9;
            m2 = 1e9;

            for(int j = 0; j < n; j++) {
                if(j == idx1) {
                    dp[i][j] = dp[i-1][idx2] + grid[i][j];
                } else {
                    dp[i][j] = dp[i-1][idx1] + grid[i][j];
                }

                if(dp[i][j] < m1) {
                    nextidx2 = nextidx1;
                    nextidx1 = j;
                    m2 = m1;
                    m1 = dp[i][j];
                } else if(dp[i][j] <= m2) {
                    nextidx2 = j;
                    m2 = dp[i][j];
                }
                // cout << dp[i][j] << " ";
            }

            idx2 = nextidx2;
            idx1 = nextidx1;
            // cout << idx1 << "|" << idx2 << "\n";
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};