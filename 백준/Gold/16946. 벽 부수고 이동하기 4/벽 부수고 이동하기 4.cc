#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int n, m;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int r, int c, int componentID, vector<vector<int>> &mat,
        vector<vector<int>> &visited) {
  queue<pii> q;
  q.push({r, c});
  visited[r][c] = componentID;
  int componentSize = 0;

  while (!q.empty()) {
    auto curr = q.front();
    int x = curr.first;
    int y = curr.second;
    q.pop();
    componentSize++;

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m || mat[nx][ny] == 1 ||
          visited[nx][ny] == componentID)
        continue;
      visited[nx][ny] = componentID;
      q.push({nx, ny});
    }
  }

  return componentSize;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  vector<vector<int>> visited(n, vector<int>(m, 0));
  vector<int> componentSizes = {-1};
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      mat[i][j] = s[j] - '0';
    }
  }

  // precompute area size..
  int componentID = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 0 && visited[i][j] == 0) {
        int size = bfs(i, j, componentID, mat, visited);
        componentSizes.emplace_back(size);
        componentID++;
      }
    }
  }

  // modify mat..
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] != 0) {
        unordered_set<int> adjComponents;
        for (int k = 0; k < 4; ++k) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] == 0)
            continue;
          adjComponents.insert(visited[nx][ny]);
        }
        for (const auto &component : adjComponents) {
          mat[i][j] += componentSizes[component];
        }
        mat[i][j] %= 10;
      }
      cout << mat[i][j];
    }
    cout << "\n";
  }

  return 0;
}