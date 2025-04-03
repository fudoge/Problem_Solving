auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
   public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<int> leftMaxima(n), rightMaxima(n);
        leftMaxima[0] = -1;
        rightMaxima[n - 1] = -1;

        for (int i = 1; i < n; i++) {
            leftMaxima[i] = max(leftMaxima[i - 1], nums[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            rightMaxima[i] = max(rightMaxima[i + 1], nums[i + 1]);
        }

        for (int i = 1; i < n - 1; i++) {
            long long val = 1LL * (leftMaxima[i] - nums[i]) * rightMaxima[i];
            if (val > ans) ans = val;
        }

        return ans;
    }
};