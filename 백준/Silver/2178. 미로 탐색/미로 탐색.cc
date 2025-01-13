#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  for (int i = 0; i < n; ++i) {
    string temp;
    cin >> temp;
    for (int j = 0; j < m; ++j) {
      mat[i][j] = temp[j] - '0';
    }
  }

  queue<pair<int, int>> q;
  q.push({0, 0});

  while (!q.empty()) {
    auto curr = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nx = curr.first + dx[i];
      int ny = curr.second + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;
      if (visited[nx][ny])
        continue;
      if (mat[nx][ny] == 0)
        continue;
      q.push({nx, ny});
      visited[nx][ny] = true;
      mat[nx][ny] = mat[curr.first][curr.second] + 1;
    }
  }

  cout << mat[n - 1][m - 1] << "\n";

  return 0;
}