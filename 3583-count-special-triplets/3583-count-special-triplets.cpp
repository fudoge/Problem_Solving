#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        ll ltable[200001], rtable[200001];
        memset(ltable, 0, sizeof(ltable));
        memset(rtable, 0, sizeof(rtable));
        for(int num : nums) {
            rtable[num]++;
        }

        ll ans = 0;
        rtable[nums[0]]--;
        ltable[nums[0]]++;
        for(int j = 1; j < n-1; j++) {
            rtable[nums[j]]--;
            int target = nums[j] * 2;
            ans = (ans + ltable[target] * rtable[target]) % MOD;
            ltable[nums[j]]++;
        }

        return ans;
    }
};