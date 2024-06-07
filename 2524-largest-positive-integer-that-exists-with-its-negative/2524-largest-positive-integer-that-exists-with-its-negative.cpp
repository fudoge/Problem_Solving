#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size()-1;
        while(i < j) {
            if(nums[i] * -1 == nums[j]) return nums[j];
            else if(nums[i] * -1 > nums[j]) i++;
            else j--;
        }
        return -1;
    }
};