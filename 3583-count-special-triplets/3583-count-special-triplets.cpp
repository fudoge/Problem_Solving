using ll = long long;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ltable(200001, 0), rtable(200001, 0);
        for(int num : nums) {
            rtable[num]++;
        }

        ll ans = 0;
        rtable[nums[0]]--;
        ltable[nums[0]]++;
        for(int j = 1; j < n-1; j++) {
            rtable[nums[j]]--;
            ans = (ans + ltable[nums[j]*2] * rtable[nums[j]*2]) % MOD;
            ltable[nums[j]]++;
        }

        return ans;
    }
};