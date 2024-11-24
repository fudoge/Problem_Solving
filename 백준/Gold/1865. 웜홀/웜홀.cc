#include <bits/stdc++.h>
#define INF 1e9
#define ll long long

using namespace std;

int t;

void floyd(vector<vector<ll>> &mat, int n) {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
      }
    }
  }
}

void solve() {
  int n, m, w;
  cin >> n >> m >> w;
  ll u, v, d;

  vector<vector<ll>> mat(n + 1, vector<ll>(n + 1, INF));
  for (int i = 1; i <= n; ++i) {
    mat[i][i] = 0;
  }

  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> d;
    mat[u][v] = min(mat[u][v], d);
    mat[v][u] = min(mat[u][v], d);
  }

  for (int i = 0; i < w; ++i) {
    cin >> u >> v >> d;
    mat[u][v] = min(mat[u][v], -1 * d);
  }

  floyd(mat, n);
  for (int i = 1; i <= n; ++i) {
    if (mat[i][i] < 0) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
  return;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
  return 0;
}