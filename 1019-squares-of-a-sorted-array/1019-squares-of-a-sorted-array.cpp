#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &num : nums) {
            num = num*num;
        }

        sort(nums.begin(), nums.end());
        return nums;
    }
};