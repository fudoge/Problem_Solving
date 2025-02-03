#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(int argc, char *argv[]) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  for (int l = 0; l < k; ++l) {
    int lbx, lby, rtx, rty;
    cin >> lbx >> lby >> rtx >> rty;
    for (int i = lby; i < rty; ++i) {
      for (int j = lbx; j < rtx; ++j) {
        visited[i][j] = true;
      }
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!visited[i][j]) {
        int size = 1;
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();

          for (int l = 0; l < 4; ++l) {
            int nx = x + dx[l];
            int ny = y + dy[l];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny])
              continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
            size++;
          }
        }

        ans.emplace_back(size);
      }
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (const auto &elem : ans) {
    cout << elem << " ";
  }
  cout << "\n";

  return 0;
}