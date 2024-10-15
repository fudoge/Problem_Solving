#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<vector<bool>> &adj, vector<bool> &visited) {
  visited[node] = true;
  for (int i = 0; i < 26; ++i) {
    if (adj[node][i] && !visited[i]) {
      dfs(i, adj, visited);
    }
  }
}

bool isConnected(vector<int> &indegree, vector<int> &outdegree,
                 vector<vector<bool>> &adj) {
  // check if it is eulerian path
  int startNode = -1;
  int endNode = -1;
  for (int i = 0; i < 26; ++i) {
    int cmp = outdegree[i] - indegree[i];
    if (cmp == 1) {
      if (startNode == -1)
        startNode = i;
      else
        return false;
    } else if (cmp == -1) {
      if (endNode == -1)
        endNode = i;
      else
        return false;
    } else if (cmp != 0)
      return false;
  }

  if (startNode == -1) {
    for (int i = 0; i < 26; ++i) {
      if (outdegree[i] > 0) {
        startNode = i;
        break;
      }
    }
  }
  vector<bool> visited(26, 0);
  dfs(startNode, adj, visited);
  for (int i = 0; i < 26; ++i) {
    if ((outdegree[i] > 0 || indegree[i] > 0) && !visited[i])
      return false;
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<int> outdegree(26, 0);
  vector<int> indegree(26, 0);
  vector<vector<bool>> graph(26, vector<bool>(26, 0));
  string temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    int first = temp[0] - 'a';
    int last = temp[temp.size() - 1] - 'a';

    outdegree[first]++;
    indegree[last]++;
    graph[first][last] = true;
  }
  if (isConnected(indegree, outdegree, graph)) {
    cout << "Ordering is possible.\n";
  } else {
    cout << "The door cannot be opened.\n";
  }
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}