class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return false;
        vector<int> prefix_sum(n, 0);
        prefix_sum[0] = nums[0] % k;
        for(int i = 1; i < n; i++) {
            prefix_sum[i] = (prefix_sum[i-1] + nums[i]) % k;
            if(prefix_sum[i] == 0) return true;
        }

        unordered_map<int, bool> mp;

        for(int i = 1; i < n; i++) {
            if(mp[prefix_sum[i]]) return true;
            mp[prefix_sum[i-1]] = true;
        }

        return false;
    }
};