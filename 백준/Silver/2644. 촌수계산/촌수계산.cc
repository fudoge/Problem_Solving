#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n, m;
int src, dst;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> src >> dst;
  cin >> m;
  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<int> dist(n + 1, INT_MAX);
  priority_queue<pii, vector<pii>, greater<>> pq;
  pq.push({src, 0});
  dist[src] = 0;

  while (!pq.empty()) {
    auto [curr, cost] = pq.top();
    pq.pop();

    if (dist[curr] < cost)
      continue;

    for (const auto &next : adj[curr]) {
      if (dist[next] > dist[curr] + 1) {
        dist[next] = dist[curr] + 1;
        pq.push({next, dist[next]});
      }
    }
  }

  cout << (dist[dst] == INT_MAX ? -1 : dist[dst]) << "\n";

  return 0;
}