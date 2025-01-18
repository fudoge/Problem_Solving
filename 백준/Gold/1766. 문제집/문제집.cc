#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<int> indegree(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int first, second;
    cin >> first >> second;
    graph[first].push_back(second);
    indegree[second]++;
  }

  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = 1; i <= n; ++i) {
    if (indegree[i] == 0)
      pq.push(i);
  }

  while (!pq.empty()) {
    int curr = pq.top();
    pq.pop();
    cout << curr << " ";

    for (const auto &next : graph[curr]) {
      indegree[next]--;
      if (indegree[next] == 0)
        pq.push(next);
    }
  }

  cout << "\n";

  return 0;
}