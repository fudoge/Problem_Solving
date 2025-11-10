#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
   public:
    int minOperations(vector<int>& nums) {
        vector<int> stack;
        int ans = 0;
        for (int num : nums) {
            while (!stack.empty() && stack.back() > num) {
                stack.pop_back();
            }

            if (num == 0) continue;
            if (stack.empty() || stack.back() < num) {
                ans++;
                stack.emplace_back(num);
            }
        }

        return ans;
    }
};