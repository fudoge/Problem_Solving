#include <bits/stdc++.h>

using namespace std;

int n, m;

int getRoot(vector<int> &parent, int x) {
  if (parent[x] == -1)
    return x;
  return parent[x] = getRoot(parent, parent[x]);
}

void unionElement(vector<int> &parent, int x, int y) {
  int xRoot = getRoot(parent, x);
  int yRoot = getRoot(parent, y);
  if (xRoot != yRoot) {
    if (xRoot < yRoot)
      parent[yRoot] = xRoot;
    else
      parent[xRoot] = yRoot;
  }
}

int main() {
  cin >> n >> m;

  int k;
  cin >> k;
  vector<bool> participants(n + 1, false); // true: knows the truth
  for (int i = 0; i < k; ++i) {
    int temp;
    cin >> temp;
    participants[temp] = true;
  }

  vector<int> parent(n + 1, -1);
  vector<vector<int>> parties(m);

  for (int i = 0; i < m; ++i) {
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int participant;
      cin >> participant;
      parties[i].push_back(participant);
      if (j > 0) {
        unionElement(parent, parties[i][j], parties[i][j - 1]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (participants[i]) {
      participants[getRoot(parent, i)] = true;
    }
  }

  int ans = 0;
  for (int i = 0; i < m; ++i) {
    bool canLie = true;
    for (const auto &member : parties[i]) {
      if (participants[getRoot(parent, member)]) {
        canLie = false;
        break;
      }
    }
    if (canLie)
      ans++;
  }

  cout << ans << "\n";

  return 0;
}