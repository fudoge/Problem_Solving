class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9+7;
        int n = arr.size();
        vector<long long> dp(n);
        int last_odd_idx = -1;
        int last2_odd_idx = -1;
        int even_streak = 1;
        if(arr[0] & 1) {
            dp[0] = 1;
            last_odd_idx = 0;
            even_streak = 0;
        }
        // cout << dp[0] << " " << last_odd_idx << " " << last2_odd_idx << " " << even_streak << "\n";
        for(int i = 1; i < n; i++) {
            if(arr[i] & 1)     {
                if(last2_odd_idx != -1) {
                    dp[i] = dp[last2_odd_idx] + even_streak + 1;
                } else {
                    dp[i] = even_streak + 1;
                }
                even_streak = 0;
                last2_odd_idx = last_odd_idx;
                last_odd_idx = i;
            } else {
                dp[i] = dp[i-1];
                even_streak++;
            }
            // cout << dp[i] << " " << last_odd_idx << " " << last2_odd_idx << " " << even_streak << "\n";
        }       

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return (int)ans;
    }
};