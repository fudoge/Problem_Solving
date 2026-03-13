using ll = long long;
class Solution {
public:
    bool check(int mountainHeight, vector<int> &workerTimes, ll time) {
        ll reduced = 0;
        for (int wt : workerTimes) {
            long double val = (long double)2 * time / wt;
            ll x = (ll)((sqrtl(1.0L + 4.0L * 2.0L * time / wt) - 1) / 2);
            while (1LL * wt * x * (x + 1) / 2 > time) x--;
            while (1LL * wt * (x + 1) * (x + 2) / 2 <= time) x++;
            reduced += x;
            if (reduced >= mountainHeight) return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int minWT = *min_element(workerTimes.begin(), workerTimes.end());
        ll lo = 0, hi = 1LL * minWT * (1LL * mountainHeight * (mountainHeight+1) / 2);

        ll ans = LLONG_MAX;
        while(lo <= hi) {
            ll mid = (lo + hi) >> 1;
            if(check(mountainHeight, workerTimes, mid)) {
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }

        return ans;
    }
};