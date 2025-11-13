#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
   public:
    int maxOperations(string s) {
        int n = s.size();
        int ans = 0;

        int init = n - 1;
        while (init >= 0 && s[init] == '1') {
            init--;
        }

        int curr_size = 0;
        int suffix_groups = 0;
        for (int i = init; i >= 0; i--) {
            if (s[i] == '1') {
                curr_size++;
                ans += (suffix_groups + 1);
            } else {
                suffix_groups += curr_size > 0 ? 1 : 0;
                curr_size = 0;
            }
        }

        return ans;
    }
};