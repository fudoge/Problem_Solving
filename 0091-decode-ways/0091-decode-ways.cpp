class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        if(n == 0 || s[0] == '0') return 0;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            auto oneDigit = s[i-1];
            auto twoDigits = s.substr(i-2, 2);

            if(oneDigit != '0')
                dp[i] += dp[i-1];
            if(stoi(twoDigits) >= 10 && stoi(twoDigits) <= 26)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};