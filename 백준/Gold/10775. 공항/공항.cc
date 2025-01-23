#include <bits/stdc++.h>
using namespace std;

int getRoot(int x, vector<int> &parent) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = getRoot(parent[x], parent);
}

bool dockPlane(int targetCell, vector<int> &parent) {
  int root = getRoot(targetCell, parent);
  if (root == 0)
    return false;
  parent[root] = root - 1;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int g, p;
  cin >> g >> p;
  vector<int> planes(p);
  for (int i = 0; i < p; ++i) {
    cin >> planes[i];
  }

  vector<int> parent(g + 1);
  iota(parent.begin(), parent.end(), 0);

  int ans = 0;
  for (const auto &plane : planes) {
    if (!dockPlane(plane, parent))
      break;
    ans++;
  }

  cout << ans << "\n";

  return 0;
}