#include <bits/stdc++.h>

using namespace std;

int getRoot(int x, vector<int> &parent) {
  if (parent[x] == x)
    return x;
  return parent[x] = getRoot(parent[x], parent);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> parent(n + 2);
  iota(parent.begin(), parent.end(), 1);

  for (int i = 0; i < m; ++i) {
    int card;
    cin >> card;

    parent[card] = card;
  }

  for (int i = 0; i < k; ++i) {
    int opponentCard;
    cin >> opponentCard;

    opponentCard++;
    int ans = getRoot(opponentCard, parent);
    parent[ans] = parent[ans + 1];
    cout << ans << "\n";
  }

  return 0;
}