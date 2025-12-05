class Solution {
   public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int r = accumulate(nums.begin(), nums.end(), 0);
        int l = 0;

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            l += nums[i];
            r -= nums[i];
            if ((l - r) % 2 == 0) ans++;
        }

        return ans;
    }
};