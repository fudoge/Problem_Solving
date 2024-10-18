#include <bits/stdc++.h>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> mat(n, vector<int>(n));
  vector<tuple<int, int, int>> viruses;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
      if (mat[i][j] != 0)
        viruses.push_back({mat[i][j], i, j});
    }
  }

  int s, x, y;
  cin >> s >> x >> y;
  sort(viruses.begin(), viruses.end());

  queue<tuple<int, int, int>> q;
  for (const auto &virus : viruses) {
    q.push(virus);
  }

  int virusNo, r, c;
  while (!q.empty() && s-- > 0) {
    int qSize = q.size();

    for (int i = 0; i < qSize; ++i) {
      tie(virusNo, r, c) = q.front();
      q.pop();

      for (int j = 0; j < 4; ++j) {
        int nr = r + dr[j];
        int nc = c + dc[j];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
          continue;
        if (mat[nr][nc] != 0)
          continue;
        mat[nr][nc] = virusNo;
        q.push({virusNo, nr, nc});
      }
    }
  }

  cout << mat[x - 1][y - 1] << "\n";

  return 0;
}