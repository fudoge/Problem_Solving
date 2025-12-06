#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
const ll MOD = 1e9+7;
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> dp(n+1);
        vector<ll> pref(n+1);
        deque<int> minQ, maxQ;

        dp[0] = 1;
        pref[0] = 1;
        for(int i = 0, j = 0; i < n; i++) {
            while(!maxQ.empty() && nums[maxQ.back()] <= nums[i]) {
                maxQ.pop_back();
            }
            maxQ.push_back(i);
            while(!minQ.empty() && nums[minQ.back()] >= nums[i]) {
                minQ.pop_back();
            }
            minQ.push_back(i);

            while(!maxQ.empty() && !minQ.empty() && nums[maxQ.front()] - nums[minQ.front()] > k) {
                if(maxQ.front() == j) {
                    maxQ.pop_front();
                }
                if(minQ.front() == j) {
                    minQ.pop_front();
                }
                j++;
            }
            dp[i+1] = (pref[i] - (j > 0 ? pref[j - 1] : 0) + MOD) % MOD;
            pref[i+1] = (pref[i] + dp[i+1]) % MOD;
        }

        return dp[n];
    }
};