#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<bool> visited(n + 1, false);

  queue<int> q;
  q.push(1);
  visited[1] = true;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

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

  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    if (visited[i])
      ans++;
  }
  cout << ans << "\n";

  return 0;
}