#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int v, e, k;
  cin >> v >> e >> k;

  vector<vector<pair<int, int>>> graph(v + 1);
  vector<int> costs(v + 1, INT_MAX);

  int from, to, weight;
  for (int i = 0; i < e; ++i) {
    cin >> from >> to >> weight;
    graph[from].push_back({to, weight});
  }

  // {cost, node};
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  costs[k] = 0;
  pq.push({0, k});
  while (!pq.empty()) {
    int currCost = pq.top().first;
    int currNode = pq.top().second;
    pq.pop();
    if (currCost > costs[currNode])
      continue;

    for (const auto &next : graph[currNode]) {
      if (currCost + next.second < costs[next.first]) {
        pq.push({currCost + next.second, next.first});
        costs[next.first] = currCost + next.second;
      }
    }
  }

  for (int i = 1; i < v + 1; ++i) {
    if (costs[i] == INT_MAX) {
      cout << "INF\n";
    } else {
      cout << costs[i] << "\n";
    }
  }

  return 0;
}