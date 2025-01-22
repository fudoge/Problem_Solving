#include <bits/stdc++.h>

using namespace std;

int n;
int ans[2]; // code0 - 밝은색, code1 - 어두운색
const int offset = 9;

int board[10][10]; // 0: wall 1: available
bool diagD[19];    // 우하향 대각선
bool diagU[19];    // 우상향 대각선

void solve(int r, int c, int code, int count) {
  if (r >= n) {
    ans[code] = max(ans[code], count);
    return;
  }

  int diagD_id = r - c + offset;
  int diagU_id = r + c;

  // 가능한경우 백트래킹
  if (board[r][c] == 1 && !diagD[diagD_id] && !diagU[diagU_id]) {
    diagD[diagD_id] = true;
    diagU[diagU_id] = true;
    board[r][c] = 2;
    if (c + 2 >= n) {
      int newC = c + 2 - n;
      if (n % 2 == 0)
        newC ^= 1;
      solve(r + 1, newC, code, count + 1);
    } else
      solve(r, c + 2, code, count + 1);
    diagD[diagD_id] = false;
    diagU[diagU_id] = false;
    board[r][c] = 1;
  }

  // 그냥 보내기
  if (c + 2 >= n) {
    int newC = c + 2 - n;
    if (n % 2 == 0)
      newC ^= 1;
    solve(r + 1, newC, code, count);
  } else
    solve(r, c + 2, code, count);
}

int main(int argc, char *argv[]) {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
    }
  }

  solve(0, 0, 0, 0);
  solve(0, 1, 1, 0);

  cout << ans[0] + ans[1] << "\n";

  return 0;
}