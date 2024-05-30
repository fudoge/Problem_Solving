class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>());
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0 && dp[i].size() < dp[j].size()) {
                    dp[i] = dp[j];
                }
            }
            dp[i].push_back(nums[i]);
        }

        int maxIdx = 0;
        for(int i = 0; i < n; i++) {
            if(dp[maxIdx].size() < dp[i].size()) maxIdx = i;
        }

        return dp[maxIdx];
    }
};