#include <bits/stdc++.h>
#define LIMIT 100001

using namespace std;

int n, k;

int first_visited[LIMIT]; // first visited step
int visited[LIMIT];       // vc[node] = count;

int main(int argc, char *argv[]) {
  for (int i = 0; i < LIMIT; ++i) {
    first_visited[i] = INT_MAX;
    visited[i] = 0;
  }
  cin >> n >> k;

  if (n == k) {
    cout << "0\n1\n";
    return 0;
  }

  first_visited[n] = 0;
  visited[n] = 1;
  int steps = 0;
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    steps++;
    int qSize = q.size();
    for (int i = 0; i < qSize; ++i) {
      int curr = q.front();
      q.pop();

      for (int next : {curr - 1, curr + 1, curr * 2}) {
        if (next >= 0 && next < LIMIT) {
          if (first_visited[next] == INT_MAX) {
            first_visited[next] = steps;
            visited[next] = visited[curr];
            q.push(next);
          } else if (first_visited[next] == steps) {
            visited[next] += visited[curr];
          }
        }
      }
    }
    if (first_visited[k] != INT_MAX)
      break;
  }

  cout << first_visited[k] << "\n";
  cout << visited[k] << "\n";

  return 0;
}