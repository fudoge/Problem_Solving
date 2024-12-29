#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;

  // dp[step][last][start]
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(3, 0)));
  int r, g, b;
  cin >> r >> g >> b;
  dp[0][0][0] = r;
  dp[0][1][1] = g;
  dp[0][2][2] = b;
  dp[0][0][1] = 1e9;
  dp[0][0][2] = 1e9;
  dp[0][1][0] = 1e9;
  dp[0][1][2] = 1e9;
  dp[0][2][0] = 1e9;
  dp[0][2][1] = 1e9;

  for (int i = 1; i < n - 1; ++i) {
    cin >> r >> g >> b;
    dp[i][0][0] = min(dp[i - 1][1][0], dp[i - 1][2][0]) + r;
    dp[i][0][1] = min(dp[i - 1][1][1], dp[i - 1][2][1]) + r;
    dp[i][0][2] = min(dp[i - 1][1][2], dp[i - 1][2][2]) + r;
    dp[i][1][0] = min(dp[i - 1][2][0], dp[i - 1][0][0]) + g;
    dp[i][1][1] = min(dp[i - 1][2][1], dp[i - 1][0][1]) + g;
    dp[i][1][2] = min(dp[i - 1][2][2], dp[i - 1][0][2]) + g;
    dp[i][2][0] = min(dp[i - 1][0][0], dp[i - 1][1][0]) + b;
    dp[i][2][1] = min(dp[i - 1][0][1], dp[i - 1][1][1]) + b;
    dp[i][2][2] = min(dp[i - 1][0][2], dp[i - 1][1][2]) + b;
  }

  cin >> r >> g >> b;

  dp[n - 1][0][0] = INT_MAX;
  dp[n - 1][1][0] = min(dp[n - 2][0][0], dp[n - 2][2][0]) + g;
  dp[n - 1][2][0] = min(dp[n - 2][0][0], dp[n - 2][1][0]) + b;
  dp[n - 1][0][1] = min(dp[n - 2][1][1], dp[n - 2][2][1]) + r;
  dp[n - 1][1][1] = INT_MAX;
  dp[n - 1][2][1] = min(dp[n - 2][0][1], dp[n - 2][1][1]) + b;
  dp[n - 1][0][2] = min(dp[n - 2][1][2], dp[n - 2][2][2]) + r;
  dp[n - 1][1][2] = min(dp[n - 2][0][2], dp[n - 2][2][2]) + g;
  dp[n - 1][2][2] = INT_MAX;

  int ans = INT_MAX;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ans = min(ans, dp[n - 1][i][j]);
    }
  }

  cout << ans << "\n";

  return 0;
}