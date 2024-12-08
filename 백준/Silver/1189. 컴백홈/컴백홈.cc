#include <bits/stdc++.h>
using namespace std;

int r, c, k;
int ans = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int dist, vector<string> &mat,
         vector<vector<bool>> &visited) {
  if (x == 0 && y == c - 1 && dist == k) {
    ans++;
    return;
  }
  if (dist > k)
    return;

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx >= r || ny < 0 || ny >= c)
      continue;
    if (mat[nx][ny] == 'T')
      continue;
    if (visited[nx][ny])
      continue;

    visited[nx][ny] = true;
    dfs(nx, ny, dist + 1, mat, visited);
    visited[nx][ny] = false;
  }
}

int main(int argc, char *argv[]) {
  cin >> r >> c >> k;
  vector<string> mat(r);
  for (int i = 0; i < r; ++i) {
    cin >> mat[i];
  }
  vector<vector<bool>> visited(r, vector<bool>(c, false));

  visited[r - 1][0] = true;
  dfs(r - 1, 0, 1, mat, visited);

  cout << ans << "\n";

  return 0;
}