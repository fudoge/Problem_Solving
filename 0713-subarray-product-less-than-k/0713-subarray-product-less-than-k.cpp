class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        const int n = nums.size();
        
        int cnt = 0;
        int product = 1;
        for (int i = 0, j = 0; j < n; j++) {
            product *= nums[j];
            while (i <= j && product >= k) {
                product /= nums[i++];
            }
            cnt += j - i + 1;
        }
        return cnt;
    }
};