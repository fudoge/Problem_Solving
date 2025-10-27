#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
   public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int prev = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = 0; j < m; j++) {
                curr += bank[i][j] - '0';
            }
            if (curr > 0) {
                ans += prev * curr;
                prev = curr;
            }
        }

        return ans;
    }
};