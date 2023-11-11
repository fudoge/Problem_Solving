#include <bits/stdc++.h>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int goalAlp = alp;
    int goalCop = cop;
    for (const auto &problem : problems) {
        if (goalAlp < problem[0]) {
            goalAlp = problem[0];
        }
        if (goalCop < problem[1]) {
            goalCop = problem[1];
        }
    }
    if(goalAlp <= alp && goalCop <= cop) return 0;
    vector<vector<int>> dp(goalAlp+1, vector<int>(goalCop+1, 1e9));
    dp[alp][cop] = 0;

    for (int i = alp; i <= goalAlp; i++) {
        for (int j = cop; j <= goalCop; j++) {
            if(i < goalAlp) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1); 
            }
            if(j < goalCop) {
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1); 
            }
            for(const auto &problem : problems) {
                int alp_req = problem[0];
                int cop_req = problem[1];
                int alp_rwd = problem[2];
                int cop_rwd = problem[3];
                int cost = problem[4];
                
                if(i >= alp_req && j >= cop_req) {
                    dp[min(i+alp_rwd, goalAlp)][min(j+cop_rwd, goalCop)] = min(dp[min(i+alp_rwd, goalAlp)][min(j+cop_rwd, goalCop)], dp[i][j] + cost);
                }
                
                
            }
        }
    }

    return dp[goalAlp][goalCop];
}
