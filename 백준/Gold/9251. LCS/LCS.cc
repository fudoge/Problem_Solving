#include <bits/stdc++.h>

using namespace std;

int n, m;
string s1, s2;

int dp[1001][1001];

int solve(int i1, int i2) {
  if (i1 >= n || i2 >= m)
    return 0;
  if (dp[i1][i2] != -1)
    return dp[i1][i2];

  int res = 0;

  if (s1[i1] == s2[i2])
    return dp[i1][i2] = solve(i1 + 1, i2 + 1) + 1;

  return dp[i1][i2] = max(solve(i1 + 1, i2), solve(i1, i2 + 1));
}

int main(int argc, char *argv[]) {
  cin >> s1 >> s2;
  n = s1.size();
  m = s2.size();
  memset(dp, -1, sizeof(dp));

  cout << solve(0, 0) << "\n";

  return 0;
}