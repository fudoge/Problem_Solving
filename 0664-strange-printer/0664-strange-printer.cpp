class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int from, int to, string &s) {
        if (from > to) return 0;
        if (dp[from][to] != -1) return dp[from][to];

        dp[from][to] = solve(from + 1, to, s) + 1;
        for (int k = from + 1; k <= to; ++k) {
            if (s[from] == s[k]) {
                dp[from][to] = min(dp[from][to], solve(from, k - 1, s) + solve(k + 1, to, s));
            }
        }
        return dp[from][to];
    }

    int strangePrinter(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        return solve(0, n - 1, s);
    }
};