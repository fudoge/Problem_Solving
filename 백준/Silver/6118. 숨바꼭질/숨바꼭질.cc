#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> dist(n + 1, INT_MAX);
  dist[1] = 0;
  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (const auto &next : graph[curr]) {
      if (dist[next] > dist[curr] + 1) {
        dist[next] = dist[curr] + 1;
        q.push(next);
      }
    }
  }

  int no = 0;
  int maxLen = 0;
  int streak = 0;
  for (int i = 1; i <= n; ++i) {
    if (maxLen < dist[i]) {
      maxLen = dist[i];
      no = i;
      streak = 1;
    } else if (maxLen == dist[i]) {
      streak++;
    }
  }

  cout << no << " " << maxLen << " " << streak << "\n";

  return 0;
}