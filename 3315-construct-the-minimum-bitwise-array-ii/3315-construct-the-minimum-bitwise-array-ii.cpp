class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            // if 2, then ans[i] = -1;
            if(nums[i] == 2) {
                ans[i] = -1;
                continue;
            }
            int x = nums[i];
            // case 111....111
            if(((x+1) & x) == 0) {
                ans[i] = (1 << (int)log2(nums[i])) - 1;
                continue;
            }
            
            int cnt = 0;
            while(x > 0) {
                if((x & 1) == 0) break;
                x >>= 1;
                cnt++;
            }
            x <<= 1;
            for(int i = 0; i < cnt-1; i++) {
                x <<= 1;
                x++;
            }
            ans[i] = x;
        }
        return ans;
    }
};