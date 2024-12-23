#include <bits/stdc++.h>

using namespace std;

int getRoot(int x, vector<int> &parent) {
  if (parent[x] == -1)
    return x;
  return parent[x] = getRoot(parent[x], parent);
}

void merge(int x, int y, vector<int> &parent) {
  if (x < y) {
    parent[y] = x;
  } else {
    parent[x] = y;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {u, v, w};
  }

  sort(edges.begin(), edges.end(),
       [](const auto &a, const auto &b) { return a[2] < b[2]; });

  vector<int> parent(n + 1, -1);
  int sum = 0;
  int maxWeight = 0;
  for (int i = 0; i < m; ++i) {
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];

    int ru = getRoot(u, parent);
    int rv = getRoot(v, parent);
    if (ru == rv)
      continue;
    merge(ru, rv, parent);

    sum += w;
    maxWeight = max(maxWeight, w);
  }

  cout << sum - maxWeight << "\n";

  return 0;
}