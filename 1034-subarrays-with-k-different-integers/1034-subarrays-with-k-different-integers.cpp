#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int K = subarray_with_atmost_k(nums, k);
        int K_1 = subarray_with_atmost_k(nums, k-1);

        return K - K_1;
    }

    int subarray_with_atmost_k(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int left = 0, right = 0, ans = 0;
        while(right < n) {
            mp[nums[right]]++;
            while(mp.size() > k) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }

            ans += right - left + 1;
            right++;
        }

        return ans;
    }
};