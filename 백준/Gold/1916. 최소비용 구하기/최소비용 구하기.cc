#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  int src, dst, cost;
  vector<vector<pair<int, int>>> graph(n + 1);
  vector<int> costs(n + 1, INT_MAX);
  for (int i = 0; i < m; ++i) {
    cin >> src >> dst >> cost;
    graph[src].push_back({dst, cost});
  }

  cin >> src >> dst;

  // {cost, node}
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, src});
  costs[src] = 0;

  while (!pq.empty()) {
    auto curr = pq.top();
    pq.pop();

    if (curr.first > costs[curr.second])
      continue;
    for (const auto &next : graph[curr.second]) {
      if (curr.first + next.second < costs[next.first]) {
        costs[next.first] = curr.first + next.second;
        pq.push({costs[next.first], next.first});
      }
    }
  }
  cout << costs[dst] << "\n";

  return 0;
}