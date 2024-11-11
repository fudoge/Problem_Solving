#include <bits/stdc++.h>

using namespace std;

int r, c;
char board[21][21];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int solve(int x, int y, int &visited) {
  int res = 0;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx >= r || ny < 0 | ny >= c)
      continue;

    int ch = board[nx][ny] - 'A';
    if ((visited & (1 << ch)) == 0) {
      visited |= (1 << ch);
      res = max(res, 1 + solve(nx, ny, visited));
      visited &= ~(1 << ch);
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> board[i][j];
    }
  }

  int visited;
  visited |= (1 << (board[0][0] - 'A'));
  cout << solve(0, 0, visited) + 1 << "\n";

  return 0;
}