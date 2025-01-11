#include <bits/stdc++.h>

using namespace std;

int n, m;
char mat[1001][1001];
int state[1001][1001];

bool traverse(int r, int c, int k) {
  int nextR = r;
  int nextC = c;
  while (state[nextR][nextC] == 0) {
    state[nextR][nextC] = k;
    switch (mat[nextR][nextC]) {
    case 'L':
      nextC--;
      break;
    case 'R':
      nextC++;
      break;
    case 'U':
      nextR--;
      break;
    case 'D':
      nextR++;
      break;
    }
  }

  return state[nextR][nextC] == k;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string temp;
    cin >> temp;
    for (int j = 0; j < m; ++j) {
      mat[i][j] = temp[j];
    }
  }

  int ans = 0;
  int k = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!state[i][j] && traverse(i, j, ++k))
        ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}