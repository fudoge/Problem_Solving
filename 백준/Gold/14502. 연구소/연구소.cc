#include <bits/stdc++.h>

using namespace std;

int n, m;
int mat[9][9];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int ans = 0;

int bfs(int r, int c, vector<vector<bool>> &visited) {
  queue<pair<int, int>> q;
  q.push({r, c});
  visited[r][c] = true;
  int res = 1;

  bool flag = false;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (mat[nx][ny] == 2) {
        flag = true;
        continue;
      }
      if (mat[nx][ny] == 1)
        continue;
      if (!visited[nx][ny]) {
        visited[nx][ny] = true;
        res++;
        q.push({nx, ny});
      }
    }
  }

  return flag ? 0 : res;
}

void solve(int left, int row, int col) {
  if (left == 0) {
    int sum = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 0 && !visited[i][j])
          sum += bfs(i, j, visited);
      }
    }
    ans = max(ans, sum);
    return;
  }

  for (int i = row; i < n; ++i) {
    if (i > row)
      col = 0;
    for (int j = col; j < m; ++j) {
      if (mat[i][j] == 0) {
        mat[i][j] = 1;
        solve(left - 1, i, j);
        mat[i][j] = 0;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  solve(3, 0, 0);
  cout << ans << "\n";

  return 0;
}