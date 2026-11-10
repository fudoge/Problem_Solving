class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int j = 1; j <= n; j++) {
            if(j >= 1) {
                int i = j-1;
                dp[j] = min(dp[j], costs[j-1] + dp[i] + 1);
            }

            if(j >= 2) {
                int i = j-2;
                dp[j] = min(dp[j], costs[j-1] + dp[i] + 4);
            }

            if(j >= 3) {
                int i = j-3;
                dp[j] = min(dp[j], costs[j-1] + dp[i] + 9);
            }
        }

        return dp[n];
    }
};