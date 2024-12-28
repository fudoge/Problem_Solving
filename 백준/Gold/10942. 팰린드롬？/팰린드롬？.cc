#include <bits/stdc++.h>

using namespace std;

int n;
int arr[2001];
bool dp[2001][2001];

bool solve() {
  int s, e;
  cin >> s >> e;
  s--;
  e--;

  return dp[s][e];
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int k = 0; i - k >= 0 && i + k < n; ++k) {
      if (arr[i - k] != arr[i + k])
        break;
      dp[i - k][i + k] = true;
    }
  }
  for (int l = 0; l < n - 1; ++l) {
    int r = l + 1;
    for (int k = 0; l - k >= 0 && r + k < n; ++k) {
      if (arr[l - k] != arr[r + k])
        break;
      dp[l - k][r + k] = true;
    }
  }

  int m;
  cin >> m;
  while (m--) {
    bool res = solve();
    if (res) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }
  return 0;
}