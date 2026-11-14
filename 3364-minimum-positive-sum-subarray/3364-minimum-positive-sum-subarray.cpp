class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int len = l; len <= r; len++) {
            int sum = accumulate(nums.begin(), nums.begin() + len, 0);
            if(sum > 0) ans = min(ans, sum);
            
            for(int j = len; j < n; j++) {
                sum -= nums[j-len];
                sum += nums[j];
                if(sum > 0) ans = min(ans, sum);
            }
        }

        return ans == INT_MAX? -1 : ans;
    }
};