#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
   public:
    int n;
    bool solve(ll target, vector<ll>& pref, int r, ll k) {
        vector<ll> added(n, 0);

        ll extrasum = 0;
        for (int i = 0; i < n; i++) {
            int leftIdx = max(i - r - 1, 0);
            int rightIdx = min(n - 1, i + r);
            ll left = i - r - 1 >= 0 ? pref[i - r - 1] : 0;
            ll right = pref[rightIdx];
            extrasum -= added[leftIdx];
            ll sum = right - left + extrasum;

            ll diff = target - sum;
            if (diff > 0) {
                if (k - diff < 0) return false;
                added[rightIdx] += diff;
                extrasum += diff;
                k -= diff;
            }
        }

        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        this->n = stations.size();
        vector<ll> pref(n, 0);
        pref[0] = stations[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + stations[i];
        }
        ll lo = 0, hi = pref.back() + k, ans = 0;

        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;

            if (solve(mid, pref, r, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};