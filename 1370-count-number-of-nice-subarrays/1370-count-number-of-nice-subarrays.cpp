class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int odds = 0;
        int ans = 0;
        while(right < n) {
            // 홀수 k개되도록 채워..
            while(right < n && odds < k) {
                if(nums[right]%2) {
                    odds++;
                }
                right++;
            }
            // 짝수인동안 계속 진행...
            int y = 1;
            while(right < n && nums[right] %2 == 0) {
                right++;
                y++;
            }
            
            int x = 1;
            while(left <= right && nums[left] %2 == 0) {
                x++;
                left++;
            }
            if(odds == k) ans += 1 * y * x;
            left++;
            odds--;
        }
        return ans;
    }
};