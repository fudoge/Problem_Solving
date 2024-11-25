#include <bits/stdc++.h>

using namespace std;

int n, m;
int src, dst;

struct comp {
  bool operator()(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0])
      return a.size() > b.size();
    return a[0] < b[0];
  }
};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n + 1);

  int u, v, w;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  cin >> src >> dst;

  vector<vector<int>> dist(n + 1, {(int)1e9}); // {비용, 경로}
  dist[src] = {0, src};

  priority_queue<vector<int>, vector<vector<int>>, comp> pq; // <비용, 경로>
  pq.push({0, src});

  while (!pq.empty()) {
    auto currState = pq.top();
    pq.pop();

    int stateSize = currState.size();
    int currNode = currState[stateSize - 1];
    int currCost = currState[0];

    if (dist[currNode][0] < currCost)
      continue;

    for (const auto &next : graph[currNode]) {
      int nextCost = currState[0] + next.second;
      if (nextCost < dist[next.first][0]) {
        vector<int> nextState(stateSize + 1);
        nextState[0] = nextCost;
        for (int i = 1; i < stateSize; ++i) {
          nextState[i] = currState[i];
        }
        nextState[stateSize] = next.first;
        dist[next.first] = nextState;
        pq.push(nextState);
      }
    }
  }

  cout << dist[dst][0] << "\n";
  cout << dist[dst].size() - 1 << "\n";
  for (int i = 1; i < dist[dst].size(); ++i) {
    cout << dist[dst][i] << " ";
  }
  cout << "\n";

  return 0;
}