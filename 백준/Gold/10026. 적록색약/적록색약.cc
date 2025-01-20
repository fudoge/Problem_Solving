#include <bits/stdc++.h>

using namespace std;

int n;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int r, int c, bool isColorblind, vector<string> &mat,
         vector<vector<bool>> &visited) {
  char comp = mat[r][c];
  char comp2 = mat[r][c];
  if (isColorblind) {
    if (comp == 'R')
      comp2 = 'G';
    else if (comp == 'G')
      comp2 = 'R';
  }
  visited[r][c] = true;
  queue<pair<int, int>> q;
  q.push({r, c});

  while (!q.empty()) {
    auto curr = q.front();
    q.pop();
    int x = curr.first;
    int y = curr.second;

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny])
        continue;
      if (!(mat[nx][ny] == comp || mat[nx][ny] == comp2))
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
  vector<string> mat;
  for (int i = 0; i < n; ++i) {
    string temp;
    cin >> temp;
    mat.emplace_back(temp);
  }

  int a = 0, b = 0;

  // 일반인
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!visited[i][j]) {
        bfs(i, j, false, mat, visited);
        a++;
      }
    }
  }

  // 적록색약
  vector<vector<bool>> visited2(n, vector<bool>(n, false));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!visited2[i][j]) {
        bfs(i, j, true, mat, visited2);
        b++;
      }
    }
  }

  cout << a << " " << b << "\n";

  return 0;
}