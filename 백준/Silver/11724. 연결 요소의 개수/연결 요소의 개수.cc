#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<bool> visited(n + 1, false);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      queue<int> q;
      q.push(i);
      visited[i] = true;
      while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (const auto &next : graph[curr]) {
          if (!visited[next]) {
            visited[next] = true;
            q.push(next);
          }
        }
      }
      ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}