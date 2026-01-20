class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            if(nums[i] == 2) {
                ans[i] = -1;
                continue;
            }

            int k = 1;
            while((k | (k+1)) != nums[i]) {
                k++;
            }
            ans[i] = k;
        }
        return ans;
    }
};