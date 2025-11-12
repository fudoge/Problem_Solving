class Solution {
   public:
    int n;
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int minOperations(vector<int>& nums) {
        n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                return n - count(nums.begin(), nums.end(), 1);
            }
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = min(ans, j - i + n - 1);
                    break;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};