#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[i-1]) {
                int x = (nums[i-1] - nums[i])+1;
                nums[i] += x;
                ans += x;
            }
        }
        return ans;
    }
};