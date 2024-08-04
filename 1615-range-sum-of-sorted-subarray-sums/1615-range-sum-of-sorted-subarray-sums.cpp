class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> newNums;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                newNums.push_back(sum);
            }
        }

        long long ans = 0;
        sort(newNums.begin(), newNums.end());
        for(int i = left-1; i < right; i++) {
            ans += newNums[i];
        }

        return ans % (int)(1e9 + 7);
    }
};