class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int n1 = count(nums.begin(), nums.end(), 1);
        if(n1 == 0 || n1 == n) return 0;

        int ans = INT_MAX;
        int cnt1 = 0;
        for(int l = 0, r = 0; r < n + n1; r++) {
            cnt1 += nums[r%n];
            if(r - l + 1 > n1) {
                cnt1 -= nums[l++ % n];
            }

            if(r - l + 1 == n1) {
                ans = min(ans, n1 - cnt1);
            }
        }

        return ans;
    }
};