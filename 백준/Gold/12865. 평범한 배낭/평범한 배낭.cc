#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;

  int w, v;
  vector<pair<int, int>> items(n);
  for (int i = 0; i < n; ++i) {
    cin >> w >> v;
    items[i] = {w, v};
  }

  vector<int> dp(k + 1, 0);
  for (int i = 0; i < n; ++i) {
    w = items[i].first;
    v = items[i].second;
    for (int j = k; j >= w; --j) {
      dp[j] = max(dp[j], dp[j - w] + v);
    }
  }

  cout << dp[k] << "\n";

  return 0;
}