#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int v;

pii bfs(int start, vector<vector<pii>> &graph) {
  int farthest = -1;
  int maxDist = -1;
  queue<int> q;
  q.push(start);
  vector<int> dist(v + 1, -1);
  dist[start] = 0;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (const auto &next : graph[curr]) {
      if (dist[next.first] == -1) {
        dist[next.first] = dist[curr] + next.second;
        q.push(next.first);

        if (dist[next.first] > maxDist) {
          maxDist = dist[next.first];
          farthest = next.first;
        }
      }
    }
  }

  return {farthest, maxDist};
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> v;
  vector<vector<pii>> graph(v + 1);
  for (int i = 0; i < v; ++i) {
    int src;
    int dst, cost;
    cin >> src;

    while (cin >> dst) {
      if (dst == -1)
        break;
      cin >> cost;
      graph[src].push_back({dst, cost});
    }
  }

  auto [endA, _] = bfs(1, graph);

  auto [__, diameter] = bfs(endA, graph);

  cout << diameter << "\n";
  return 0;
}