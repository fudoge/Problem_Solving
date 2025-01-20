#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};

void bfs(int r, int c, vector<vector<int>> &mat, vector<vector<bool>> &visited,
         int h, int w) {
  queue<pair<int, int>> q;
  q.push({r, c});
  visited[r][c] = true;

  while (!q.empty()) {
    auto curr = q.front();
    int x = curr.first;
    int y = curr.second;
    q.pop();

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        int nx = x + dx[i];
        int ny = y + dy[j];

        if (nx < 0 || ny < 0 || nx >= h || ny >= w || mat[nx][ny] == 0 ||
            visited[nx][ny])
          continue;
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}

int solve(int w, int h) {
  vector<vector<int>> mat(h, vector<int>(w));
  vector<vector<bool>> visited(h, vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> mat[i][j];
    }
  }

  int res = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!visited[i][j] && mat[i][j] == 1) {
        bfs(i, j, mat, visited, h, w);
        res++;
      }
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int w, h;
  while ((cin >> w >> h) && !(w == 0 && h == 0)) {
    cout << solve(w, h) << "\n";
  }
  return 0;
}