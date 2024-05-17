class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(*max_element(nums.begin(), nums.end()) < 0) return *max_element(nums.begin(), nums.end());
        int curr_sum = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < n; i++) {
            curr_sum = max(nums[i], curr_sum + nums[i]);
            max_sum = max(max_sum, curr_sum);
        }

        return max_sum;
    }
};