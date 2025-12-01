#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
   public:
    bool check(ll time, int n, vector<int>& batteries) {
        ll tot = 0;
        for (ll b : batteries) {
            tot += min(b, time);
        }

        return tot >= time * n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll sum = accumulate(batteries.begin(), batteries.end(), 0LL);

        ll lo = 0;
        ll hi = sum / n;
        ll ans = 0;

        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            if (check(mid, n, batteries)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};