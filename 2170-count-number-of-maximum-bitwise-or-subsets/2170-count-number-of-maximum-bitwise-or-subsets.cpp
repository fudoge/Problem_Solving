#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
private:
    int maxOR;
    int n;
    int ans;
    void solve(int i, int masked, vector<int>& nums) {
        if(i >= n) {
            if(masked == maxOR) ans++;
            return;
        }

        solve(i+1, masked, nums);
        solve(i+1, masked | nums[i], nums);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        for(const auto &num : nums) {
            maxOR |= num;
        }

        solve(0, 0, nums);

        return ans;
    }
};