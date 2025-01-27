#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
  int h, w;
  cin >> h >> w;

  int ans = 0;
  vector<vector<char>> mat(h + 2, vector<char>(w + 2, '.'));
  vector<vector<short>> visited(h + 2, vector<short>(w + 2, false));
  vector<vector<pii>> doorMap(26);
  vector<bool> hasKey(26, false);
  queue<pii> q;
  for (int i = 0; i < h; ++i) {
    string temp;
    cin >> temp;
    for (int j = 0; j < w; ++j) {
      mat[i + 1][j + 1] = temp[j];
      if (mat[i + 1][j + 1] >= 'A' && mat[i + 1][j + 1] <= 'Z') {
        doorMap[mat[i + 1][j + 1] - 'A'].push_back({i + 1, j + 1});
      }
    }
  }

  string keys;
  cin >> keys;
  if (keys != "0") {
    for (char key : keys) {
      hasKey[key - 'a'] = true;
    }
  }

  q.push({0, 0});
  while (!q.empty()) {
    auto curr = q.front();
    int x = curr.first;
    int y = curr.second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= h + 2 || ny >= w + 2 ||
          visited[nx][ny] != 0)
        continue;

      if (mat[nx][ny] >= 'A' && mat[nx][ny] <= 'Z') {
        if (hasKey[mat[nx][ny] - 'A']) {
          q.push({nx, ny});
          visited[nx][ny] = 1;
        } else {
          visited[nx][ny] = 2;
        }
      } else if (mat[nx][ny] >= 'a' && mat[nx][ny] <= 'z') {
        q.push({nx, ny});
        visited[nx][ny] = 1;
        if (!hasKey[mat[nx][ny] - 'a']) {
          hasKey[mat[nx][ny] - 'a'] = true;
          for (const auto &elem : doorMap[mat[nx][ny] - 'a']) {
            if (visited[elem.first][elem.second] == 2) {
              visited[elem.first][elem.second] = 1;
              q.push({elem.first, elem.second});
            }
          }
        }
      } else if (mat[nx][ny] == '$') {
        ans++;
        q.push({nx, ny});
        visited[nx][ny] = 1;
      } else if (mat[nx][ny] == '.') {
        q.push({nx, ny});
        visited[nx][ny] = 1;
      }
    }
  }

  cout << ans << "\n";
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}