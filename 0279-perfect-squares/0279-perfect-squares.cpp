class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        vector<int> dp(n+1, 1e9);
        // base case
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 1; i <= int(sqrt(n)); i++) {
            squares.push_back(i*i); // {1, 4, 9 ... }
        }

        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < squares.size(); j++) {
                if(i-squares[j] < 0) break; // 이전 수가 더 없으면 그만두기
                dp[i] = min(dp[i], dp[i-squares[j]] + 1);
            }
        }

        return dp[n];
    }
};