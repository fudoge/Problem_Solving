#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> cols, primaryDiag,
    secondaryDiag; // primaryDiag: topleft -> bottomright // secondaryDiag:
                   // bottomleft -> topright

int solve(int row) {
  if (row >= n)
    return 1;
  int res = 0;
  for (int col = 0; col < n; ++col) {
    if (cols[col] || primaryDiag[row + col] || secondaryDiag[row - col + n - 1])
      continue;

    cols[col]++;
    primaryDiag[row + col]++;
    secondaryDiag[row - col + n - 1]++;
    res += solve(row + 1);
    cols[col]--;
    primaryDiag[row + col]--;
    secondaryDiag[row - col + n - 1]--;
  }
  return res;
}

int main(int argc, char *argv[]) {
  cin >> n;
  cols.resize(n, 0);
  primaryDiag.resize(2 * n - 1, 0);
  secondaryDiag.resize(2 * n - 1, 0);
  cout << solve(0) << "\n";
  return 0;
}