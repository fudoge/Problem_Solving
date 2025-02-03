#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<ll>> adj = {{0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0, 0},
                          {1, 1, 0, 1, 0, 1, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0},
                          {0, 0, 0, 1, 0, 1, 1, 0}, {0, 0, 1, 1, 1, 0, 0, 1},
                          {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0}};

vector<vector<ll>> matMul(vector<vector<ll>> a, vector<vector<ll>> b) {
  vector<vector<ll>> c(8, vector<ll>(8, 0));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
      c[i][j] %= MOD;
    }
  }
  return c;
}

vector<vector<ll>> solve(int d) {
  if (d == 1)
    return adj;

  if (d % 2 == 0) {
    auto x = solve(d / 2);
    return matMul(x, x);
  }

  return matMul(solve(d - 1), adj);
}

int main(int argc, char *argv[]) {
  int d;
  cin >> d;

  auto res = solve(d);
  cout << res[0][0] << "\n";

  return 0;
}