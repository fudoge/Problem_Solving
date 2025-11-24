#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
   public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<bool> ans;
        for (int num : nums) {
            sum += num;
            sum %= 5;
            ans.emplace_back(sum ? false : true);
            sum <<= 1;
        }

        return ans;
    }
};