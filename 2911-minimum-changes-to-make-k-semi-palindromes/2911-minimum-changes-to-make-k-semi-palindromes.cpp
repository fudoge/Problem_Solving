#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int palin_cost(string &s) {
        int l = 0, r = s.size()-1;
        int res = 0;
        while(l < r) {
            if(s[l] != s[r]) res++;
            l++;
            r--;
        }

        return res;
    }
    int semi(string &s, int l, int r) {
        int len = r - l + 1;
        int res = INT_MAX;
        for(int d = 1; d < len; d++) {
            if(len % d == 0) {
                vector<string> group(d);
                for(int i = l; i <= r; i++) {
                    group[(i-l)%d] += s[i];
                }
                int sum = 0;
                for(int i = 0; i < d; i++) {
                    sum += palin_cost(group[i]);
                }
                res = min(res, sum);
            }
        }

        return res;
    }
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));
        for(int l = 0; l < n; l++) {
            for(int r = l+1; r < n; r++) {
                cost[l][r] = semi(s, l, r);
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(k+1, INF));
        dp[0][0] = 0;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                if(i < 2 * j) continue;
                for(int prev = 2*(j-1); prev <= i-2; prev++) {
                    dp[i][j] = min(dp[i][j], dp[prev][j-1] + cost[prev][i-1]);
                }
            }
        }

        return dp[n][k];
    }
};