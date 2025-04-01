class Solution {
   public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long ans = 0;
        int n = questions.size();
        vector<long long> dp(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            int next = i + questions[i][1] + 1;
            if (next < n) {
                dp[i] = questions[i][0] + dp[next];
            } else {
                dp[i] = questions[i][0];
            }
            if (i < n - 1) dp[i] = max(dp[i], dp[i + 1]);
            // cout << "dp[" << i << "]: " << dp[i] << "\n";
        }

        return dp[0];
    }
};