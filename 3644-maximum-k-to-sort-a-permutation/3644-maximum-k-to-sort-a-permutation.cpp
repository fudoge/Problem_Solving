class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = (1 << int(ceil(log2(n)))) - 1;

        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                ans &= nums[i];
                flag = false;
            }
        }

        return flag ? 0 : ans;
    }
};