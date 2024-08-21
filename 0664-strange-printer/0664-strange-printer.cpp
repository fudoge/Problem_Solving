#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int from, int to, string &s) {
        if (from > to) return 0;
        if (dp[from][to] != -1) return dp[from][to];

        dp[from][to] = solve(from + 1, to, s) + 1;
        for (int i = from + 1; i <= to; ++i) {
            if (s[from] == s[i]) {
                dp[from][to] = min(dp[from][to], solve(from, i - 1, s) + solve(i + 1, to, s));
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