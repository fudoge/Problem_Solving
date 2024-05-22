const int MOD = 1e9+7;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int maxLen = min(steps, arrLen);
        
        vector<vector<int>> dp(steps+1, vector<int>(maxLen, -1));
        
        return solve(steps, maxLen, 0, dp);
    }

    int solve(int leftSteps, int maxLen, int index, vector<vector<int>> &dp) {
    	// 남은 행동의 개수가 0인데, 인덱스도 0이면 경우의 수 하나 추가
        if (leftSteps == 0) return (index == 0) ? 1 : 0;
        // 범위를 벗어나면 제외
        if (index < 0 || index >= maxLen) return 0;
        // 값이 있으면 반환
        if (dp[leftSteps][index] != -1) return dp[leftSteps][index];

		// 오른쪽, 왼쪽, 가만히 있을 때의 경우의 수들을 재귀적으로 계산
        int rightMove = solve(leftSteps - 1, maxLen, index + 1, dp) % MOD;
        int leftMove = solve(leftSteps - 1, maxLen, index - 1, dp) % MOD;
        int stayMove = solve(leftSteps - 1, maxLen, index, dp) % MOD;
		
        // 경우의 수들 누적 후 저장
        dp[leftSteps][index] =((rightMove + leftMove)%MOD+ stayMove) % MOD;

        return dp[leftSteps][index];
    }
};