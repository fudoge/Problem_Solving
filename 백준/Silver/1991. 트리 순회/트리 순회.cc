#include <bits/stdc++.h>

using namespace std;

void preorder(vector<pair<int, int>> &graph, int root) {
  cout << (char)(root + 'A');
  if (graph[root].first >= 0 && graph[root].first < 26) {
    preorder(graph, graph[root].first);
  }
  if (graph[root].second >= 0 && graph[root].second < 26) {
    preorder(graph, graph[root].second);
  }
}

void inorder(vector<pair<int, int>> &graph, int root) {
  if (graph[root].first >= 0 && graph[root].first < 26) {
    inorder(graph, graph[root].first);
  }
  cout << (char)(root + 'A');

  if (graph[root].second >= 0 && graph[root].second < 26) {
    inorder(graph, graph[root].second);
  }
}

void postorder(vector<pair<int, int>> &graph, int root) {
  if (graph[root].first >= 0 && graph[root].first < 26) {
    postorder(graph, graph[root].first);
  }

  if (graph[root].second >= 0 && graph[root].second < 26) {
    postorder(graph, graph[root].second);
  }
  cout << (char)(root + 'A');
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<pair<int, int>> graph(26);
  char parent, left, right;
  for (int i = 0; i < n; ++i) {
    cin >> parent >> left >> right;
    graph[parent - 'A'] = {left - 'A', right - 'A'};
  }
  int root = 0;

  preorder(graph, root);
  cout << "\n";
  inorder(graph, root);
  cout << "\n";
  postorder(graph, root);
  cout << "\n";

  return 0;
}