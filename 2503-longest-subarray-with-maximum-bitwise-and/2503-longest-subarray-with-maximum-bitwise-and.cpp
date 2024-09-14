class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = 0;
        for(const auto &num : nums) {
            maxNum = max(maxNum, num);
        }

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == maxNum) {
                int len = 0;
                while(i < nums.size() && nums[i] == maxNum) {
                    i++;
                    len++;
                }
                ans = max(ans, len);
            }
        }

        return ans;
    }
};