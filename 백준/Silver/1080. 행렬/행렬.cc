#include <iostream>
#include <vector>

using namespace std;

int n, m;

void flip(int row, int col, vector<vector<int>>& mat) {
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      mat[row + i][col + j] ^= 1;
    }
  }
}

bool isFinished(vector<vector<int>>& mat) {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(mat[i][j]) return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));

  string temp;
  for(int i = 0; i < n; ++i) {
    cin >> temp;
    for(int j = 0; j < m; ++j) {
      mat[i][j] = temp[j] - '0';
    }

  }

  for(int i = 0; i < n; ++i) {
    cin >> temp;
    for(int j = 0; j < m; ++j) {
      mat[i][j] ^= temp[j] - '0';
    }
  }

  int cnt = 0;
  for(int i = 0; i < n-2; ++i) {
    for(int j = 0; j < m-2; ++j) {
      if(mat[i][j] == 1) {
        flip(i, j, mat);
        cnt++;
      }
    }
  }

  if(isFinished(mat)) {
    cout << cnt << "\n";
  } else {
    cout << -1 << "\n";
  }

  return 0;
}