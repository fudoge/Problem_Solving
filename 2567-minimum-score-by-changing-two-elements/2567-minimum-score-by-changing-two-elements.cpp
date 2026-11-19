#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        int h1 = INT_MIN, h2, h3, l1 = INT_MAX, l2, l3;
        for(int i = 0; i < n; i++) {
            if(nums[i] > h1) {
                h3 = h2;
                h2 = h1;
                h1 = nums[i];
            } else if(nums[i] > h2) {
                h3 = h2;
                h2 = nums[i];
            } else if(nums[i] > h3) {
                h3 = nums[i];
            }  
            
            if(nums[i] < l1) {
                l3 = l2;
                l2 = l1;
                l1 = nums[i];
            } else if(nums[i] < l2) {
                l3 = l2;
                l2 = nums[i];
            } else if(nums[i] < l3) {
                l3 = nums[i];
            }
        }

        return min(h1-l3, min(h2-l2, h3-l1));
    }
};
