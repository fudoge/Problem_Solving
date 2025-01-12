#include <bits/stdc++.h>

using namespace std;

int n;
int ans;

void solve(int depth, int movecode, vector<vector<int>> mat) {
  if (depth >= 5) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans = max(ans, mat[i][j]);
      }
    }
    return;
  }

  // L, R, U, D
  if (movecode == 0) {
    for (int i = 0; i < n; ++i) {
      int k = 0;
      int lastNum = mat[i][0] == 0 ? -1 : mat[i][0];
      for (int j = 1; j < n; ++j) {
        if (lastNum == mat[i][j]) {
          mat[i][k++] = lastNum * 2;
          lastNum = -1;
        } else if (mat[i][j] != 0) {
          if (lastNum != -1)
            mat[i][k++] = lastNum;
          lastNum = mat[i][j];
        }
      }
      if (lastNum != -1)
        mat[i][k++] = lastNum;
      for (int j = k; j < n; ++j) {
        mat[i][j] = 0;
      }
    }
  } else if (movecode == 1) {
    for (int i = 0; i < n; ++i) {
      int k = n - 1;
      int lastNum = mat[i][n - 1] == 0 ? -1 : mat[i][n - 1];
      for (int j = n - 2; j >= 0; --j) {
        if (lastNum == mat[i][j]) {
          mat[i][k--] = lastNum * 2;
          lastNum = -1;
        } else if (mat[i][j] != 0) {
          if (lastNum != -1)
            mat[i][k--] = lastNum;
          lastNum = mat[i][j];
        }
      }
      if (lastNum != -1)
        mat[i][k--] = lastNum;
      for (int j = k; j >= 0; --j) {
        mat[i][j] = 0;
      }
    }
  } else if (movecode == 2) {
    for (int j = 0; j < n; ++j) {
      int k = 0;
      int lastNum = mat[0][j] == 0 ? -1 : mat[0][j];
      for (int i = 1; i < n; ++i) {
        if (lastNum == mat[i][j]) {
          mat[k++][j] = lastNum * 2;
          lastNum = -1;
        } else if (mat[i][j] != 0) {
          if (lastNum != -1)
            mat[k++][j] = lastNum;
          lastNum = mat[i][j];
        }
      }
      if (lastNum != -1)
        mat[k++][j] = lastNum;
      for (int i = k; i < n; ++i) {
        mat[i][j] = 0;
      }
    }
  } else {
    for (int j = 0; j < n; ++j) {
      int k = n - 1;
      int lastNum = mat[n - 1][j] == 0 ? -1 : mat[n - 1][j];
      for (int i = n - 2; i >= 0; --i) {
        if (lastNum == mat[i][j]) {
          mat[k--][j] = lastNum * 2;
          lastNum = -1;
        } else if (mat[i][j] != 0) {
          if (lastNum != -1)
            mat[k--][j] = lastNum;
          lastNum = mat[i][j];
        }
      }
      if (lastNum != -1)
        mat[k--][j] = lastNum;
      for (int i = k; i >= 0; --i) {
        mat[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < 4; ++i) {
    solve(depth + 1, i, mat);
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  ans = 0;
  vector<vector<int>> mat(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  for (int i = 0; i < 4; ++i) {
    solve(0, i, mat);
  }

  cout << ans << "\n";
  return 0;
}