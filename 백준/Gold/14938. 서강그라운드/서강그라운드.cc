#include <bits/stdc++.h>
#define INF 1000000000

using namespace std;

int n, m, r;

int items[101];
int dist[101][101];

void floyd() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < 101; ++i) {
    for (int j = 0; j < 101; ++j) {
      dist[i][j] = i == j ? 0 : INF;
    }
  }

  cin >> n >> m >> r;
  for (int i = 1; i <= n; ++i) {
    cin >> items[i];
  }

  int a, b, l;
  for (int i = 0; i < r; ++i) {
    cin >> a >> b >> l;
    dist[a][b] = l;
    dist[b][a] = l;
  }

  floyd();

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int gain = 0;
    for (int j = 1; j <= n; ++j) {
      if (dist[i][j] <= m)
        gain += items[j];
    }
    ans = max(ans, gain);
  }

  cout << ans << "\n";

  return 0;
}