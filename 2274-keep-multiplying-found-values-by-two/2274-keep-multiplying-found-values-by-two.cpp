#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
   public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> freq(2001, 0);
        for (const auto& num : nums) {
            freq[num]++;
        }

        while (freq[original]) {
            original *= 2;
        }

        return original;
    }
};