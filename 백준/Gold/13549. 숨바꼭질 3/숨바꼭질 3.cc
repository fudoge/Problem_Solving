#include <bits/stdc++.h>

using namespace std;

int n, k;
int dist[100001];

int main(int argc, char *argv[]) {
  cin >> n >> k;
  fill_n(dist, 100001, INT_MAX);

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, n});

  dist[n] = 0;

  while (!pq.empty()) {
    auto curr = pq.top();
    pq.pop();

    if (dist[curr.second] < curr.first)
      continue;
    if (curr.second - 1 >= 0 && curr.first + 1 < dist[curr.second - 1]) {
      dist[curr.second - 1] = curr.first + 1;
      pq.push({curr.first + 1, curr.second - 1});
    }
    if (curr.second + 1 < 100001 && curr.first + 1 < dist[curr.second + 1]) {
      dist[curr.second + 1] = curr.first + 1;
      pq.push({curr.first + 1, curr.second + 1});
    }
    if (curr.second * 2 < 100001 && curr.first < dist[curr.second * 2]) {
      dist[curr.second * 2] = curr.first;
      pq.push({curr.first, curr.second * 2});
    }
  }

  cout << dist[k] << "\n";

  return 0;
}