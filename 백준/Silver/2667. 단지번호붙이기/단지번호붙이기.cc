#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int r, int c, vector<vector<int>> &mat, vector<vector<bool>> &visited) {
  queue<pii> q;
  q.push({r, c});
  visited[r][c] = true;
  int cnt = 1;

  while (!q.empty()) {
    auto curr = q.front();
    q.pop();
    int x = curr.first;
    int y = curr.second;

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= n)
        continue;
      if (visited[nx][ny] || mat[nx][ny] == 0)
        continue;
      cnt++;
      q.push({nx, ny});
      visited[nx][ny] = true;
    }
  }
  return cnt;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;

  vector<vector<int>> mat(n, vector<int>(n));
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  for (int i = 0; i < n; ++i) {
    string temp;
    cin >> temp;
    for (int j = 0; j < n; ++j) {
      mat[i][j] = temp[j] - '0';
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] != 0 && !visited[i][j]) {
        int res = bfs(i, j, mat, visited);
        ans.emplace_back(res);
      }
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (const auto &elem : ans) {
    cout << elem << "\n";
  }

  return 0;
}