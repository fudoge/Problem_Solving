#include <bits/stdc++.h>

using namespace std;

int n;

void putOnBoard(int r, int c, vector<vector<int>> &board) {
  for (int i = 0; i < n; ++i) {
    board[r][i]++;
    board[i][c]++;
  }
  for (int i = 1; r + i < n && c - i >= 0; ++i) {
    board[r + i][c - i]++;
  }
  for (int i = 1; r - i >= 0 && c + i < n; ++i) {
    board[r - i][c + i]++;
  }
  for (int i = 1; r - i >= 0 && c - i >= 0; ++i) {
    board[r - i][c - i]++;
  }
  for (int i = 1; r + i < n && c + i < n; ++i) {
    board[r + i][c + i]++;
  }

  board[r][c]--;
}

void removeFromBoard(int r, int c, vector<vector<int>> &board) {
  for (int i = 0; i < n; ++i) {
    board[r][i]--;
    board[i][c]--;
  }
  for (int i = 1; r + i < n && c - i >= 0; ++i) {
    board[r + i][c - i]--;
  }
  for (int i = 1; r - i >= 0 && c + i < n; ++i) {
    board[r - i][c + i]--;
  }
  for (int i = 1; r - i >= 0 && c - i >= 0; ++i) {
    board[r - i][c - i]--;
  }
  for (int i = 1; r + i < n && c + i < n; ++i) {
    board[r + i][c + i]--;
  }

  board[r][c]++;
}

int solve(int row, vector<vector<int>> &board) {
  if (row >= n) {
    return 1;
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (board[row][i] == 0) {
      putOnBoard(row, i, board);
      res += solve(row + 1, board);
      removeFromBoard(row, i, board);
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  vector<vector<int>> board(n, vector<int>(n, 0));

  cout << solve(0, board) << "\n";

  return 0;
}