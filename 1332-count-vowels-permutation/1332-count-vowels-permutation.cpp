class Solution {
public:
    const int MOD = 1e9+7;

    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n, vector<long>(5, 0));
        
        // Initialize base case: strings of length 1
        for (int i = 0; i < 5; ++i) {
            dp[0][i] = 1;
        }

        // Fill the dp array for lengths from 2 to n
        for (int i = 1; i < n; ++i) {
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]) % MOD; // 'a' follows 'e', 'i', 'u'
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;              // 'e' follows 'a', 'i'
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % MOD;              // 'i' follows 'e', 'o'
            dp[i][3] = dp[i-1][2] % MOD;                             // 'o' follows 'i'
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % MOD;              // 'u' follows 'i', 'o'
        }

        // Sum up the results for the last length
        long sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum = (sum + dp[n-1][i]) % MOD;
        }

        return sum;
    }
};
