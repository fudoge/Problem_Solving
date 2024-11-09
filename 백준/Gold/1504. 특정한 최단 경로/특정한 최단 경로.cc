#include <bits/stdc++.h>

using namespace std;

int n, e;

int dijkstra(int src, int dst, vector<vector<pair<int, int>>> graph) {
  vector<int> dist(n + 1, INT_MAX);
  dist[src] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, src});

  while (!pq.empty()) {
    auto curr = pq.top();
    pq.pop();
    int distance = curr.first;
    int node = curr.second;
    if (distance > dist[node])
      continue;

    for (const auto &next : graph[node]) {
      if (distance + next.second < dist[next.first]) {
        dist[next.first] = distance + next.second;
        pq.push({distance + next.second, next.first});
      }
    }
  }

  return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> e;
  vector<vector<pair<int, int>>> graph(n + 1);

  int src, dst, weight;
  for (int i = 0; i < e; ++i) {
    cin >> src >> dst >> weight;
    graph[src].push_back({dst, weight});
    graph[dst].push_back({src, weight});
  }

  int stop1, stop2;
  cin >> stop1 >> stop2;

  int intersection = dijkstra(stop1, stop2, graph);
  if (intersection == -1) {
    cout << "-1\n";
    return 0;
  }

  int path1_start = dijkstra(1, stop1, graph);
  int path1_end = dijkstra(stop2, n, graph);

  int path2_start = dijkstra(1, stop2, graph);
  int path2_end = dijkstra(stop1, n, graph);

  int ans1 = (path1_start < 0 || path1_end < 0)
                 ? -1
                 : path1_start + intersection + path1_end;
  int ans2 = (path2_start < 0 || path2_end < 0)
                 ? -1
                 : path2_start + intersection + path2_end;

  if (ans1 == -1 && ans2 == -1) {
    cout << "-1\n";
  } else if (ans1 == -1) {
    cout << ans2 << "\n";
  } else if (ans2 == -1) {
    cout << ans1 << "\n";
  } else {
    cout << min(ans1, ans2) << "\n";
  }

  return 0;
}