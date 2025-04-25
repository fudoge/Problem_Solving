class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long ans = 0;
        int pref = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            pref += nums[i] % modulo == k;
            ans += mp[(pref-k+modulo)%modulo];
            mp[pref%modulo]++;
        } 

        return ans;
    }
};