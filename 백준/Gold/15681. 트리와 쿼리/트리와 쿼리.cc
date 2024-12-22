#include <bits/stdc++.h>

using namespace std;

int n, r, q;
void solve(int root, vector<bool> &visited, vector<vector<int>> &graph,
           vector<int> &subtreesize) {
  for (const auto &child : graph[root]) {
    if (!visited[child]) {
      visited[child] = true;
      solve(child, visited, graph, subtreesize);
      subtreesize[root] += subtreesize[child];
    }
  }
  subtreesize[root]++;
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> r >> q;
  vector<vector<int>> graph(n + 1);

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<int> subtreesize(n + 1, 0);
  vector<bool> visited(n + 1, false);
  visited[r] = true;
  solve(r, visited, graph, subtreesize);

  for (int i = 0; i < q; ++i) {
    int root;
    cin >> root;
    cout << subtreesize[root] << "\n";
  }

  return 0;
}