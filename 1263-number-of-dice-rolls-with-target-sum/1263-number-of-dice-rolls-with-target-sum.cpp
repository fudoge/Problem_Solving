static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
private:
    const int MOD = 1e9+7;  
    vector<vector<int>> dp;  

public:
    int solve(int left, int k, int target) {
        if(left == 0) {
            if(target == 0) return 1;
            return 0;
        }
        
        if(dp[left][target] != -1) return dp[left][target];
        
        int answer = 0;
        for(int i = 1; i <= k; i++) {
            if(target-i < 0) continue;
            answer = (answer + solve(left-1, k, target-i))%MOD;
        }
        return dp[left][target] = answer;
        
    }

    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1, vector<int>(target+1, -1));

        return solve(n, k, target);
    }
};