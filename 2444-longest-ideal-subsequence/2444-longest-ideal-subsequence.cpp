class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(27, 0);
        const int n = s.size();

        for(int i = n-1; i >= 0; i--) {
            char ch = s[i];
            int idx = ch - 'a';
            int len = -1;

            int left = max((idx - k), 0);
            int right = min((idx + k), 26);

            for(int j = left; j <= right; j++) {
                len = max(len, dp[j]);
            }

            dp[idx] = len+1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};