#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int y = 0;
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') {
                y++;
            }
        } 
        vector<int> dp(n+1);
        dp[0] = y;
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            if(customers[i-1] == 'Y') {
                dp[i]--;
            } else {
                dp[i]++;
            }
            if(dp[i] < dp[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};