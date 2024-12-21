#include <bits/stdc++.h>

using namespace std;

int v, e;

void union_group(int x, int y, vector<int> &parent) {
  if (x < y) {
    parent[y] = x;
  } else {
    parent[x] = y;
  }
}

int getRoot(int x, vector<int> &parent) {
  if (parent[x] == -1)
    return x;
  else
    return parent[x] = getRoot(parent[x], parent);
}

int main(int argc, char *argv[]) {
  cin >> v >> e;

  vector<vector<int>> edges(e);
  for (int i = 0; i < e; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {u, v, w};
  }
  sort(edges.begin(), edges.end(), [](const auto &a, const auto &b) {
    if (a[2] == b[2])
      return a[0] < b[0];
    return a[2] < b[2];
  });

  vector<int> parent(v + 1, -1);

  long long cost = 0;
  for (int i = 0; i < e; ++i) {
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];

    if (getRoot(u, parent) == getRoot(v, parent))
      continue;
    union_group(getRoot(u, parent), getRoot(v, parent), parent);
    cost += w;
  }

  cout << cost << "\n";

  return 0;
}