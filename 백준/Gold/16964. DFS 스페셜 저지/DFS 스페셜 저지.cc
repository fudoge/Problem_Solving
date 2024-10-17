#include <bits/stdc++.h>

using namespace std;

int n;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  vector<vector<int>> graph(n + 1);
  int parent, child;
  for (int i = 0; i < n - 1; ++i) {
    cin >> parent >> child;
    graph[parent].emplace_back(child);
    graph[child].emplace_back(parent);
  }

  queue<int> q;
  int tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    q.push(tmp);
  }

  if (q.front() != 1) {
    cout << "0\n";
    return 0;
  }

  vector<bool> visited(n + 1, false);
  visited[q.front()] = true;
  stack<int> stk;
  stk.push(q.front());
  q.pop();

  while (!q.empty()) {
    int next = q.front();
    q.pop();

    while (!stk.empty() &&
           find(graph[stk.top()].begin(), graph[stk.top()].end(), next) ==
               graph[stk.top()].end()) {
      stk.pop();
    }
    if (stk.empty()) {
      cout << "0\n";
      return 0;
    }
    visited[next] = true;
    stk.push(next);
  }

  for (int i = 1; i < n + 1; ++i) {
    if (!visited[i]) {
      cout << "0\n";
      return 0;
    }
  }

  cout << "1\n";
  return 0;
}