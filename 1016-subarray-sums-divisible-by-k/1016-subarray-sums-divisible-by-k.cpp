class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSums(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefixSums[i + 1] = (prefixSums[i] + nums[i]) % k;
            if (prefixSums[i + 1] < 0) {
                prefixSums[i + 1] += k;
            }
        }

        int ans = 0;
        unordered_map<int, int> countMap;
        countMap[0] = 1;

        for(int i = 1; i <= n; i++) {
            ans += countMap[prefixSums[i]];
            countMap[prefixSums[i]]++;
        }

        return ans;
    }
};
