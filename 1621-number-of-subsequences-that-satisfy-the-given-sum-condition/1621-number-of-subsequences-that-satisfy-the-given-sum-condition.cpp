class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9 + 7;
        long answer = 0;
        sort(nums.begin(), nums.end());
        
        vector<int> pow2(n, 1);
        
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }
        
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                answer = (answer + pow2[right - left]) % mod;
                left++;
            }
        }
        return answer;
    }
};