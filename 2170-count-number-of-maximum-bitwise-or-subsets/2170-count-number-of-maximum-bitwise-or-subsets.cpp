#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int limit = 1 << n;
        int maxOR = 0;
        for(const auto &num : nums) {
            maxOR |= num;
        }

        int ans = 0;
        for(int i = 0; i < limit; ++i) {
            int k = i;
            int x = 0;
            for(int j = 0; j < n; ++j) {
                x |= (k % 2 == 1)? nums[j] : 0;
                k >>= 1;
            }
            if(x == maxOR) ans++;
        }
        return ans;
    }
};