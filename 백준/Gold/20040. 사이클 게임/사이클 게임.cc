#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[500001];
int groupsize[500001];

int turn = 1;

int a, b;

int getRoot(int x) {
  if (parent[x] == -1)
    return x;
  return parent[x] = getRoot(parent[x]);
}

void merge(int a, int b) {
  if (a > b)
    swap(a, b);
  parent[b] = a;
  groupsize[a] += groupsize[b];
  groupsize[b] = 0;
}

bool solve() {
  cin >> a >> b;

  int rootA = getRoot(a);
  int rootB = getRoot(b);

  if (rootA == rootB && groupsize[rootA] >= 3) {
    cout << turn << "\n";
    return true;
  }

  merge(rootA, rootB);

  turn++;
  return false;
}

int main(int argc, char *argv[]) {
  cin >> n >> m;
  memset(parent, -1, sizeof(parent));
  for (int i = 0; i < 500001; ++i) {
    groupsize[i]++;
  }
  while (m--) {
    bool res = solve();
    if (res) {
      while (m--)
        cin >> a >> b;
      exit(0);
    }
  }

  cout << "0\n";

  return 0;
}