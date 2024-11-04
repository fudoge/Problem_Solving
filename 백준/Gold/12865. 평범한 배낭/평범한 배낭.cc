#include <bits/stdc++.h>

using namespace std;

int n, k;

int dp[101][100001];
vector<pair<int, int>> items;

int solve(int idx, int leftWeight) {
  if (idx >= n)
    return 0;
  if (dp[idx][leftWeight] != -1)
    return dp[idx][leftWeight];

  int res = 0;
  if (items[idx].first <= leftWeight) {
    res = solve(idx + 1, leftWeight - items[idx].first) + items[idx].second;
  }
  res = max(res, solve(idx + 1, leftWeight));

  return dp[idx][leftWeight] = res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  items.resize(n);
  memset(dp, -1, sizeof(dp));

  int w, v;
  for (int i = 0; i < n; ++i) {
    cin >> w >> v;
    items[i].first = w;
    items[i].second = v;
  }
  sort(items.begin(), items.end());

  cout << solve(0, k) << "\n";

  return 0;
}