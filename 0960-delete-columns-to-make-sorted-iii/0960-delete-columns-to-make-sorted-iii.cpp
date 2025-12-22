class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<int> dp(m, 1);
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < i; j++) {
                bool ok = true;
                for(int r = 0; r < n; r++) {
                    if(strs[r][j] > strs[r][i]) { ok = false; break;}
                }
                if(ok) dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return m - *max_element(dp.begin(), dp.end());
    }
};