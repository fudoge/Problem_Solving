#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
   public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int l = lower - nums[i];
            int u = upper - nums[i];

            int llb = lower_bound(nums.begin()+i+1, nums.end(), l) - nums.begin();
            int rlb =
                lower_bound(nums.begin()+i+1, nums.end(), u + 1) - nums.begin();

            if(rlb > llb) ans += (rlb - llb);
        }

        return ans;
    }
};