class Solution {
    int n;
    int m;
    vector<vector<vector<int>>> dp;
public:
    int getMax(int row, int col1, int col2) {
        int maxNum = -1;

        for(int i = max(0, col1-1); i <= min(m-1, col1+1); i++) {
            for(int j = max(0, col2-1); j <= min(m-1, col2+1); j++) {
                maxNum = max(maxNum, dp[row-1][i][j]);
            }
        }
        return maxNum;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(m, -1)));

        dp[0][0][m-1] = grid[0][0] + grid[0][m-1];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                    int prev = getMax(i, j, k);
                    if(prev == -1) continue;
                    dp[i][j][k] = prev + grid[i][j] + grid[i][k];
                    if(j == k) dp[i][j][k] -= grid[i][j];
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dp[n-1][i][j]);
            }
        }

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         for(int k = 0; k < m; k++) {
        //             cout << "i, j, k: " << i << " " << j << " " << k << " " << dp[i][j][k] <<"|";
        //         }
        //     }
        //     cout << endl;
        // }

        return ans;       
    }
};