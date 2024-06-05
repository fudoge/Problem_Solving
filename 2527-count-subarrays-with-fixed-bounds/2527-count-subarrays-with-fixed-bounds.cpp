#pragma GCC optimize("03", "unroll-loops");

static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int invalid_idx = -1, min_idx = -1, max_idx = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (!(minK <= nums[i] && nums[i] <= maxK)) {
                invalid_idx = i;
            }

            if (nums[i] == minK) {
                min_idx = i;
            }

            if (nums[i] == maxK) {
                max_idx = i;
            }

            ans += max(0, min(min_idx, max_idx) - invalid_idx);
        }

        return ans;
    }
};