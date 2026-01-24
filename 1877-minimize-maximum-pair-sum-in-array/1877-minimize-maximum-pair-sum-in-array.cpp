#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < n/2; i++) {
            ans = max(ans, nums[i] + nums[n-i-1]);
        }
        return ans;
    }
};