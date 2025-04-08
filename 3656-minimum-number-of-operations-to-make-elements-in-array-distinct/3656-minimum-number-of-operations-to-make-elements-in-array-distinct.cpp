#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
   public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int dup = 0;
        for (const auto& num : nums) {
            freq[num]++;
        }

        for (const auto& [k, v] : freq) {
            if (v > 1) dup++;
        }

        if (dup == 0) return 0;

        for (int i = 0; i < n; i += 3) {
            if (--freq[nums[i]] == 1) dup--;
            if (i + 1 < n && --freq[nums[i + 1]] == 1) dup--;
            if (i + 2 < n && --freq[nums[i + 2]] == 1) dup--;
            if (dup == 0) return i / 3 + 1;
        }

        return n / 3 + 1;
    }
};