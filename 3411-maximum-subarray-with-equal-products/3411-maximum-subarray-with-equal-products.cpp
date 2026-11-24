class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int left = -1;
        vector<int> primes = {2, 3, 5, 7};
        vector<int> last_occured(10, -1);
        int ans = 2;
        for(int right = 0; right < n; right++) {
            int num = nums[right];
            for(int p : primes) {
                if(num % p == 0) {
                    if(last_occured[p] != -1) left = max(left, last_occured[p]);
                    last_occured[p] = right;
                }
            }
            ans = max(ans, right - left);
        }

        return ans;
    }
};