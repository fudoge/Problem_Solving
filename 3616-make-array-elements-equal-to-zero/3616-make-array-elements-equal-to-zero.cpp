#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
   public:
    int solve(int curr, vector<ll>& pref) {
        int l = pref[curr];
        int r = pref.back() - pref[curr];

        int diff = l - r;
        int res = 0;
        if (diff == 0 || diff == 1) res++;
        if (diff == 0 || diff == -1) res++;

        return res;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<ll> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
        for (int curr = 0; curr < n; curr++) {
            if (nums[curr] != 0) continue;
            ans += solve(curr, pref);
        }

        return ans;
    }
};