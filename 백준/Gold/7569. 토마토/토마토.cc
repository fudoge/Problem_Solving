#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, h;

  cin >> m >> n >> h;
  queue<tuple<int, int, int>> q;
  vector<vector<vector<int>>> mat(h, vector<vector<int>>(n, vector<int>(m)));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        cin >> mat[i][j][k];
        if (mat[i][j][k] == 1) {
          q.push(make_tuple(i, j, k));
        }
      }
    }
  }

  int ans = 0;
  while (!q.empty()) {
    int qsize = q.size();
    for (int k = 0; k < qsize; ++k) {
      auto [x, y, z] = q.front();
      q.pop();

      for (int i = 0; i < 6; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nz = z + dz[i];

        if (nx < 0 || ny < 0 || nz < 0 || nx >= h || ny >= n || nz >= m ||
            mat[nx][ny][nz] == -1 || mat[nx][ny][nz] == 1)
          continue;
        mat[nx][ny][nz] = 1;
        q.push(make_tuple(nx, ny, nz));
      }
    }
    ans++;
  }

  bool flag = true;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        if (mat[i][j][k] == 0)
          flag = false;
      }
    }
  }

  cout << (flag ? ans - 1 : -1) << "\n";

  return 0;
}