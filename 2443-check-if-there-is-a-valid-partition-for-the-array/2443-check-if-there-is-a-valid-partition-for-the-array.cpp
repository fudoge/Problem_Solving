class Solution {
public:
    bool validPartition(vector<int>& nums) {
        const int n = nums.size();

        vector<bool> dp(n + 1, false);
        dp[0] = true;
    
        for (int i = 1; i <= n; i++) {
            if (i >= 2 && nums[i - 1] == nums[i - 2] && dp[i - 2]) {
                dp[i] = true;
            }
            if (i >= 3) {
                if ((nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3]) || 
                    (nums[i - 1] == nums[i - 2] + 1 && nums[i - 2] == nums[i - 3] + 1)) {
                    if (dp[i - 3]) {
                        dp[i] = true;
                    }
                }
            }
        }

        return dp[n];
    }
};