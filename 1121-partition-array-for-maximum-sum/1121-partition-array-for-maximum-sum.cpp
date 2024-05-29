class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int start = n-1; start >= 0; start--) {
            int maxVal = 0;
            int end = min(n, start+k);

            for(int i = start; i < end; i++) {
                maxVal = max(maxVal, arr[i]);
                dp[start % (k+1)] = max(dp[start % (k+1)], dp[(i+1) % (k+1)] + maxVal * (i-start+1));
            }
        }

        return dp[0];
    }
};