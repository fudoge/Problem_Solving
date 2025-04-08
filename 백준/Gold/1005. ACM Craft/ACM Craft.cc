#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> graph(n + 1, vector<int>());
  vector<int> startTime(n + 1, 0);
  vector<int> workTime(n + 1);
  vector<int> indegree(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> workTime[i];
  }

  int u, v;
  for (int i = 0; i < k; ++i) {
    cin >> u >> v;
    graph[u].push_back(v);
    indegree[v]++;
  }
  int w;
  cin >> w;

  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (const auto &next : graph[curr]) {
      indegree[next]--;
      startTime[next] = max(startTime[next], startTime[curr] + workTime[curr]);
      if (indegree[next] == 0) {
        q.push(next);
      }
    }
  }
  cout << startTime[w] + workTime[w] << "\n";
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}