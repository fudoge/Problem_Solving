#include <bits/stdc++.h>
#define MOD 1000000000
#define ll long long
using namespace std;

int n;
ll dp[101][1024][10]; // dp[length][state][last]

int main() {
  cin >> n;
  for (int i = 1; i <= 9; i++) {
    dp[1][1 << i][i] = 1;
  }

  // DP 점화식
  for (int length = 2; length <= n; length++) {
    for (int state = 0; state < (1 << 10); state++) {
      for (int last = 0; last <= 9; last++) {
        if (dp[length - 1][state][last] == 0)
          continue;

        if (last > 0) {
          int nextState = state | (1 << (last - 1));
          dp[length][nextState][last - 1] += dp[length - 1][state][last];
          dp[length][nextState][last - 1] %= MOD;
        }
        if (last < 9) {
          int nextState = state | (1 << (last + 1));
          dp[length][nextState][last + 1] += dp[length - 1][state][last];
          dp[length][nextState][last + 1] %= MOD;
        }
      }
    }
  }

  ll result = 0;
  for (int last = 0; last <= 9; last++) {
    result += dp[n][(1 << 10) - 1][last];
    result %= MOD;
  }

  cout << result << "\n";

  return 0;
}