class Solution {
public:
    int dp[301][11];
    vector<int> jobDiff;
    int n;
    int solve(int idx, int leftday) {
        if(idx > n) return 1e9;
        if(leftday == 0) {
            if(idx == n) return 0;
            else return 1e9;
        }
        else if(idx == n) return 1e9;
        
        if(dp[idx][leftday] != -1) return dp[idx][leftday];

        int maxInt = jobDiff[idx];
        int result = 1e9;

        for(int i = idx; i < n; i++) {
            maxInt = max(maxInt, jobDiff[i]);
            result = min(result, maxInt + solve(i+1, leftday-1));
        }

        return dp[idx][leftday] = result;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        jobDiff = jobDifficulty;
        memset(dp, -1, sizeof(dp));
        n = jobDiff.size();
        if(n < d) return -1;

        return solve(0, d);
    }
};