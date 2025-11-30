using ll = long long;
class Solution {
   public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        int target = sum % p;
        if (target == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        ll pref = 0;
        int ans = n;

        for (int i = 0; i < n; i++) {
            pref = (pref + nums[i]) % p;
            int need = (pref - target + p) % p;
            if (mp.count(need)) {
                ans = min(ans, i - mp[need]);
            }

            mp[pref] = i;
        }

        return ans == n ? -1 : ans;
    }
};