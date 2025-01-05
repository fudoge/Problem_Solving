#include <bits/stdc++.h>
#include <queue>
#define pii pair<int, int>

using namespace std;

int n;
vector<vector<int>> costs = {{1, 2, 2, 2, 2},
                             {2, 1, 3, 4, 3},
                             {2, 3, 1, 3, 4},
                             {2, 4, 3, 1, 3},
                             {2, 3, 4, 3, 1}};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<int> arr;
  int temp;
  while ((cin >> temp) && temp != 0) {
    arr.push_back(temp);
  }
  n = arr.size();
  vector<vector<vector<int>>> dp(n + 1,
                                 vector<vector<int>>(5, vector<int>(5, 1e9)));
  dp[0][0][0] = 0;
  for (int seq = 1; seq <= n; ++seq) {
    int target = arr[seq - 1];
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        if (i != target)
          dp[seq][i][target] =
              min(dp[seq][i][target], dp[seq - 1][i][j] + costs[j][target]);
        if (j != target)
          dp[seq][target][j] =
              min(dp[seq][target][j], dp[seq - 1][i][j] + costs[i][target]);
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      ans = min(ans, dp[n][i][j]);
    }
  }
  cout << ans << "\n";

  return 0;
}