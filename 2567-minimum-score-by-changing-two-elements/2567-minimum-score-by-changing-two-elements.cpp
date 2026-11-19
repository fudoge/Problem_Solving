#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

// started_at: 09:12
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> cands;
        cands.push_back(nums[n-1] - nums[2]);
        cands.push_back(nums[n-2] - nums[1]);
        cands.push_back(nums[n-3] - nums[0]);

        return *min_element(cands.begin(), cands.end());
    }
};
