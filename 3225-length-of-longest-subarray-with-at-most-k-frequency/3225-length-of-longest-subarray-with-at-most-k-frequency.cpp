#pragma GCC optimize("03", "unroll-loops");

static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> mp;
        int maxLength = 0;

        for(int i = 0 , j = 0; j < n; j++) {
            mp[nums[j]]++;

            while(mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};