#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n+1);
  vector<float> water(n+1, 0.0);
  for(int i = 0; i < m; ++i) {
    int v, w;
    cin >> v >> w;
    graph[v].push_back(w);
  }

  water[1] = 100.0;

  for(int i = 1; i <= n; ++i) {
    int outdegree = graph[i].size();
    for(const auto &next : graph[i]) {
      water[next] += water[i] / outdegree;
    }
    if(outdegree > 0) water[i] = 0.0;
  }

  float maxWater = *max_element(water.begin(), water.end());
  cout << maxWater << "\n";
  return 0;
}