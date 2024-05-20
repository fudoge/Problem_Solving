class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int m = 1 << n;
        for(int i = 1; i < m; i++) {
            int x = 0;
            for(int j = 0; j < n; j++) {
                if((1 << j) & i) {
                    x ^= nums[j];
                }
            }
            ans += x;
        }
        return ans;
    }
};