#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;
ll prefixSum[1025][1025];

ll query(int x1, int y1, int x2, int y2) {
  ll res = prefixSum[x2][y2];
  if (x1 > 0) {
    res -= prefixSum[x1 - 1][y2];
  }
  if (y1 > 0) {
    res -= prefixSum[x2][y1 - 1];
  }
  if (x1 > 0 && y1 > 0) {
    res += prefixSum[x1 - 1][y1 - 1];
  }

  return res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> prefixSum[i][j];
    }
  }

  for (int i = 1; i < n; ++i) {
    prefixSum[i][0] += prefixSum[i - 1][0];
    prefixSum[0][i] += prefixSum[0][i - 1];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] -
                        prefixSum[i - 1][j - 1] + prefixSum[i][j];
    }
  }

  int x1, y1, x2, y2;
  for (int i = 0; i < m; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << query(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << "\n";
  }

  return 0;
}