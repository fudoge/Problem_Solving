#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(vector<vector<int>> &mat) {
  vector<vector<vector<int>>> minDistance(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
  queue<tuple<int, int, int>> q;
  
  q.emplace(0, 0, 0);
  minDistance[0][0][0] = 1;

  while (!q.empty()) {
    int x, y, broken;
    tie(x, y, broken) = q.front();
    q.pop();

    if (x == n - 1 && y == m - 1)
      return minDistance[x][y][broken];

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;

      if (mat[nx][ny] == 1 && broken == 0 && minDistance[nx][ny][1] == INT_MAX) {
        minDistance[nx][ny][1] = minDistance[x][y][0] + 1;
        q.emplace(nx, ny, 1);
      } else if (mat[nx][ny] == 0 && minDistance[nx][ny][broken] == INT_MAX) {
        minDistance[nx][ny][broken] = minDistance[x][y][broken] + 1;
        q.emplace(nx, ny, broken);
      }
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  string temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    for (int j = 0; j < m; ++j) {
      mat[i][j] = temp[j] - '0';
    }
  }

  int ans = bfs(mat);
  cout << ans << "\n";
  return 0;
}