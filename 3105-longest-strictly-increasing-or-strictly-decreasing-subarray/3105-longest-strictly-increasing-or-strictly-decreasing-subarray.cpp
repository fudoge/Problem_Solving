class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size()   ;
        if(n == 1) return 1;

        int incStreak = 1;
        int decStreak = 1;
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            if(nums[i] > nums[i-1]) {
                decStreak++;
                incStreak = 1;
            } else if(nums[i] < nums[i-1]) {
                incStreak++;
                decStreak = 1;
            } else {
                incStreak = 1;
                decStreak = 1;
            }
            ans = max(ans, max(incStreak, decStreak));
        }

        return ans;
    }
};