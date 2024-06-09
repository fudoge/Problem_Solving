class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        nums[0] %= k;
        if(nums[0] < 0) nums[0] += k;
        for(int i = 1; i < n; i++) {
            nums[i] = (nums[i] + nums[i-1]) % k;
            if(nums[i] < 0) nums[i] += k;
        }
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            ans += mp[nums[i]];

            mp[nums[i]]++;
        }

        return ans;
    }
};