class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int total_count = 0;

        vector<unordered_map<int, int>> dp(n);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j]; 

                if (diff > INT_MAX || diff < INT_MIN)
                    continue; 

                int diff_int = static_cast<int>(diff);

				// nums[j], nums[i]로 시작(i: j야 나랑 부분순열 시작하자)
                dp[i][diff_int] += 1; 
				
                // 만약에 같은 diff로 이어지던 게 있다면, 경우의 수 누적. 여기서는 요소가 3개 이상이므로 총합에 더해도 됨
                if (dp[j].count(diff_int)) {
                    dp[i][diff_int] += dp[j][diff_int];
                    total_count += dp[j][diff_int];
                }
            }
        }

        return total_count;
    }
};