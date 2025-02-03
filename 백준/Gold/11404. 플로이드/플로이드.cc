#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m;
int adj[101][101];

void floyd() {

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (adj[i][j] > adj[i][k] + adj[k][j]) {
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  cin >> n >> m;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i != j)
        adj[i][j] = INF;
      else
        adj[i][j] = 0;
    }
  }

  int u, v, w;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    if (adj[u][v] > w)
      adj[u][v] = w;
  }

  floyd();

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (adj[i][j] == INF)
        adj[i][j] = 0;
      cout << adj[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}