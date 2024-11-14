#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, b;
vector<vector<int>> mat;

int calc(int i, int j, vector<vector<int>> &m1, vector<vector<int>> &m2) {
  // i row x j col
  int res = 0;
  for (int k = 0; k < n; ++k) {
    res += m1[i][k] * m2[k][j];
    res %= 1000;
  }
  return res;
}

vector<vector<int>> solve(ll x) {
  if (x == 1) {
    return mat;
  }

  vector<vector<int>> res(n, vector<int>(n));
  if (x % 2 == 0) {
    auto m = solve(x / 2);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        res[i][j] = calc(i, j, m, m);
      }
    }
    return res;
  } else {
    auto m = solve(x - 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        res[i][j] = calc(i, j, m, mat);
      }
    }
    return res;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> b;
  mat.resize(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
      mat[i][j] %= 1000;
    }
  }

  auto ans = solve(b);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}