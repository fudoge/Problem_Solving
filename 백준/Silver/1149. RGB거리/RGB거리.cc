#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<int>> info(n, vector<int>(3));
  vector<vector<int>> dp(n, vector<int>(3));

  for (int i = 0; i < n; ++i) {
    cin >> info[i][0] >> info[i][1] >> info[i][2];
    dp[i][0] = info[i][0];
    dp[i][1] = info[i][1];
    dp[i][2] = info[i][2];
  }
  for (int i = 1; i < n; ++i) {
    dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] += min(dp[i - 1][2], dp[i - 1][0]);
    dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
  }

  cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";

  return 0;
}