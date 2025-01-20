#include <bits/stdc++.h>

using namespace std;

int n;

int mat[101][101];
bool visited[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int r, int c, int height) {
  queue<pair<int, int>> q;
  q.push({r, c});
  visited[r][c] = true;

  while (!q.empty()) {
    auto curr = q.front();
    int x = curr.first;
    int y = curr.second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= n || mat[nx][ny] <= height ||
          visited[nx][ny])
        continue;
      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int maxHeight = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
      maxHeight = max(maxHeight, mat[i][j]);
    }
  }

  int ans = 1;
  for (int h = 1; h < maxHeight; ++h) {
    int temp = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visited[i][j] && mat[i][j] > h) {
          bfs(i, j, h);
          temp++;
        }
      }
    }
    ans = max(ans, temp);
    memset(visited, false, sizeof(visited));
  }

  cout << ans << "\n";

  return 0;
}