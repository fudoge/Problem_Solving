#include <bits/stdc++.h>

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard)
{
    temperature += 10;
    t1 += 10;
    t2 += 10;

    const int time = onboard.size();
    const int lowest = min(temperature, t1);
    const int highest = max(temperature, t2);

    vector<vector<int>> dp(time + 1, vector<int>(highest + 1, 1e6));
    dp[0][temperature] = 0;
    // int last_onboard = -1;
    for (int i = 0; i < time; i++)
    {
        int from;
        int to;
        if (onboard[i])
        {
            // last_onboard = i;
            from = t1;
            to = t2;
        }
        else
        {
            from = lowest;
            to = highest;
        }

        for (int j = from; j <= to; j++)
        {
            // 온도 낮추기
            if (j + 1 <= highest)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j + 1] + a);
            }

            // 온두 높이기
            if (j - 1 >= lowest)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - 1] + a);
            }

            // 그냥 유지
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b);

            // off
            //  껐을때 온도가 내려감.
            if (j+1 > temperature && j + 1 <= highest)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j + 1]);
            }

            // 껐을 때 온도가 올라감.
            if (j-1 < temperature && j - 1 >= lowest)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - 1]);
            }
            // 아니면 온도가 같다?
            if (j == temperature && j <= highest && j >= lowest)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
        }
    }

    // for (int i = 0; i <= time; i++)
    // {
    //     for (int j = lowest; j <= highest; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "onboard: " << onboard[i];
    //     cout << endl;
    // }
    
    // int energy = 1e9;
    // for(int i = 0; i < dp[last_onboard+1].size(); i++) {
    //     if(i >= t1 && i >= t2) {
    //         energy = min(energy, dp[last_onboard+1][i]);
    //     }
    // }
    
    // return energy;

    return *min_element(dp[time].begin(), dp[time].end());
}