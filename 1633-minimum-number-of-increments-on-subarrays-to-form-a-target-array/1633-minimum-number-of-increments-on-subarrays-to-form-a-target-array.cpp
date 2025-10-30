
#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
   public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0];
        for (int i = 1; i < n; i++) {
            int diff = target[i] - target[i - 1];
            if (diff > 0) {
                ans += diff;
            }
        }

        return ans;
    }
};