#pragma GCC optimize("O3", "unroll-loops");
static const int init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int M = *max_element(nums.begin(), nums.end());
        
        int left = 0;
        int cnt = 0;
        long long ans = 0;
        for(int right = 0; right < n; right++) {
            if(nums[right] == M) {
                cnt++;
            }

            if(cnt == k) {
                while(left < right && nums[left] != M) {
                    left++;
                }
                left++;
                cnt--;
                // cout << left << " " << right << "\n";
            }
            ans += left;
        }

        return ans;
    }
};