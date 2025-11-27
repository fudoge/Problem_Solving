#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
   public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> minPref(k, LLONG_MAX);
        ll ans = LLONG_MIN;
        ll pref = 0;
        for (int i = 0; i < n; i++) {
            pref += nums[i];
            int r = (i + 1) % k;

            if ((i + 1) % k == 0) ans = max(ans, pref);
            if (minPref[r] != LLONG_MAX) {
                ans = max(ans, pref - minPref[r]);
            }

            minPref[r] = min(minPref[r], pref);
        }

        return ans;
    }
};