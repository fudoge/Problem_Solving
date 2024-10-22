#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<int>> graph(n + 1);
  int src, dst;
  for (int i = 0; i < n - 1; ++i) {
    cin >> src >> dst;
    graph[src].push_back(dst);
    graph[dst].push_back(src);
  }

  queue<int> q;
  vector<int> parent(n + 1);
  vector<bool> visited(n + 1, false);

  q.push(1);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (const auto &next : graph[curr]) {
      if (visited[next])
        continue;
      parent[next] = curr;
      visited[next] = true;
      q.push(next);
    }
  }

  for (int i = 2; i < n + 1; ++i) {
    cout << parent[i] << "\n";
  }
  return 0;
}