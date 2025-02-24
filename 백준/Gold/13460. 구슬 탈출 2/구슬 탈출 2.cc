#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans = INT_MAX;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  vector<string> mat(n);
  int rr, rc, br, bc;
  for (int i = 0; i < n; ++i) {
    cin >> mat[i];
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 'R') {
        rr = i;
        rc = j;
        mat[i][j] = '.';
      } else if (mat[i][j] == 'B') {
        br = i;
        bc = j;
        mat[i][j] = '.';
      }
    }
  }

  queue<tuple<int, int, int, int, int>>
      q; // rr, rc, br, bc, last_move(0: row, 1: col);
  q.push(make_tuple(rr, rc, br, bc, 0));
  q.push(make_tuple(rr, rc, br, bc, 1));

  int step = 0;
  while (!q.empty()) {
    int qsize = q.size();
    step++;
    if (step >= 11)
      break;
    for (int k = 0; k < qsize; ++k) {

      int rx, ry, bx, by, last_move;
      tie(rx, ry, bx, by, last_move) = q.front();
      q.pop();

      if (last_move == 0) {
        // tilt left-right
        bool rFlag = false;
        bool bFlag = false;
        int nry = ry;
        for (int j = nry - 1; j >= 0; --j) {
          if (mat[rx][j] == '#') {
            nry = j + 1;
            break;
          } else if (mat[rx][j] == 'O') {
            rFlag = true;
            break;
          }
        }
        int nby = by;
        for (int j = nby - 1; j >= 0; --j) {
          if (mat[bx][j] == '#') {
            nby = j + 1;
            break;
          } else if (mat[bx][j] == 'O') {
            bFlag = true;
            break;
          }
        }
        if (rx == bx && nry == nby && !rFlag && !bFlag) {
          if (ry < by)
            nby++;
          else
            nry++;
        }
        if (rFlag && !bFlag) {
          cout << step << "\n";
          return 0;
        }
        if (!bFlag)
          q.push(make_tuple(rx, nry, bx, nby, last_move ^ 1));

        rFlag = false;
        bFlag = false;
        nry = ry;
        for (int j = nry + 1; j < m; ++j) {
          if (mat[rx][j] == '#') {
            nry = j - 1;
            break;
          } else if (mat[rx][j] == 'O') {
            rFlag = true;
            break;
          }
        }
        nby = by;
        for (int j = nby + 1; j < m; ++j) {
          if (mat[bx][j] == '#') {
            nby = j - 1;
            break;
          } else if (mat[bx][j] == 'O') {
            bFlag = true;
            break;
          }
        }
        if (rx == bx && nry == nby && !rFlag && !bFlag) {
          if (ry < by)
            nry--;
          else
            nby--;
        }
        if (rFlag && !bFlag) {
          cout << step << "\n";
          return 0;
        }
        if (!bFlag)
          q.push(make_tuple(rx, nry, bx, nby, last_move ^ 1));
      } else {
        // tilt up-down
        bool rFlag = false;
        bool bFlag = false;
        int nrx = rx;
        for (int i = nrx - 1; i >= 0; --i) {
          if (mat[i][ry] == '#') {
            nrx = i + 1;
            break;
          } else if (mat[i][ry] == 'O') {
            rFlag = true;
            break;
          }
        }
        int nbx = bx;
        for (int i = nbx - 1; i >= 0; --i) {
          if (mat[i][by] == '#') {
            nbx = i + 1;
            break;
          } else if (mat[i][by] == 'O') {
            bFlag = true;
            break;
          }
        }
        if (nrx == nbx && ry == by && !rFlag && !bFlag) {
          if (rx < bx)
            nbx++;
          else
            nrx++;
        }
        if (rFlag && !bFlag) {
          cout << step << "\n";
          return 0;
        }
        if (!bFlag)
          q.push(make_tuple(nrx, ry, nbx, by, last_move ^ 1));

        rFlag = false;
        bFlag = false;
        nrx = rx;
        for (int i = nrx + 1; i < n; ++i) {
          if (mat[i][ry] == '#') {
            nrx = i - 1;
            break;
          } else if (mat[i][ry] == 'O') {
            rFlag = true;
            break;
          }
        }
        nbx = bx;
        for (int i = nbx + 1; i < n; ++i) {
          if (mat[i][by] == '#') {
            nbx = i - 1;
            break;
          } else if (mat[i][by] == 'O') {
            bFlag = true;
            break;
          }
        }
        if (nrx == nbx && ry == by && !rFlag && !bFlag) {
          if (rx < bx)
            nrx--;
          else
            nbx--;
        }
        if (rFlag && !bFlag) {
          cout << step << "\n";
          return 0;
        }
        if (!bFlag)
          q.push(make_tuple(nrx, ry, nbx, by, last_move ^ 1));
      }
    }
  }

  cout << "-1\n";

  return 0;
}