#include <bits/stdc++.h>

using namespace std;

struct shark {
  int id;
  int r;
  int c;
  int s;
  int d;
  int z;
  bool isAlive;

  shark(int id, int r, int c, int s, int d, int z)
      : id(id), r(r), c(c), s(s), d(d), z(z), isAlive(true) {}
};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int r, c, m;
  cin >> r >> c >> m;

  vector<shark *> arr(m);
  for (int i = 0; i < m; ++i) {
    int row, col, s, d, z;
    cin >> row >> col >> s >> d >> z;
    if (d == 1 || d == 2) {
      if (s >= 2 * (r - 1))
        s %= 2 * (r - 1);
    } else {
      if (s >= 2 * (c - 1))
        s %= 2 * (c - 1);
    }
    arr[i] = new shark(i, row - 1, col - 1, s, d, z);
  }

  int ans = 0;
  for (int i = 0; i < c; ++i) {
    int highestID = -1;
    int highestRow = r;
    for (const auto &sh : arr) {
      if (!(sh->isAlive) || sh->c != i)
        continue;
      if (highestRow > sh->r) {
        highestRow = sh->r;
        highestID = sh->id;
      }
    }

    if (highestID != -1) {
      arr[highestID]->isAlive = false;
      ans += arr[highestID]->z;
    }

    vector<vector<int>> tempMat(r, vector<int>(c, -1));
    for (const auto &sh : arr) {
      if (!(sh->isAlive))
        continue;
      int dir = sh->d;
      int newRow;
      int newCol;
      if (dir == 1) {
        newCol = sh->c;
        int toWall = sh->r;
        int toNextWall = toWall + r - 1;
        if (sh->s <= toWall) {
          newRow = (sh->r) - (sh->s);
          if (newRow == 0)
            sh->d = 2;
        } else if (sh->s <= toNextWall) {
          newRow = (sh->s) - toWall;
          if (newRow != r - 1)
            sh->d = 2;
        } else {
          newRow = r - 1 - ((sh->s) - toNextWall);
        }
      } else if (dir == 2) {
        newCol = sh->c;
        int toWall = r - 1 - (sh->r);
        int toNextWall = toWall + r - 1;
        if (sh->s <= toWall) {
          newRow = (sh->r) + (sh->s);
          if (newRow == r - 1)
            sh->d = 1;
        } else if (sh->s <= toNextWall) {
          newRow = toNextWall - (sh->s);
          if (newRow != 0)
            sh->d = 1;
        } else {
          newRow = (sh->s) - toNextWall;
        }
      } else if (dir == 3) {
        newRow = sh->r;
        int toWall = c - 1 - (sh->c);
        int toNextWall = toWall + c - 1;
        if (sh->s <= toWall) {
          newCol = (sh->c) + (sh->s);
          if (newCol == c - 1)
            sh->d = 4;
        } else if (sh->s <= toNextWall) {
          newCol = toNextWall - (sh->s);
          if (newCol != 0)
            sh->d = 4;
        } else {
          newCol = (sh->s) - toNextWall;
        }
      } else {
        newRow = sh->r;
        int toWall = sh->c;
        int toNextWall = toWall + c - 1;
        if (sh->s <= toWall) {
          newCol = (sh->c) - (sh->s);
          if (newCol == 0)
            sh->d = 3;
        } else if ((sh->s) <= toNextWall) {
          newCol = (sh->s) - toWall;
          if (newCol != c - 1)
            sh->d = 3;
        } else {
          newCol = c - 1 - ((sh->s) - toNextWall);
        }
      }

      if (tempMat[newRow][newCol] == -1) {
        tempMat[newRow][newCol] = sh->id;
      } else {
        if (arr[tempMat[newRow][newCol]]->z < sh->z) {
          arr[tempMat[newRow][newCol]]->isAlive = false;
          tempMat[newRow][newCol] = sh->id;
        } else {
          sh->isAlive = false;
        }
      }
    }

    for (int row = 0; row < r; ++row) {
      for (int col = 0; col < c; ++col) {
        if (tempMat[row][col] != -1) {
          arr[tempMat[row][col]]->r = row;
          arr[tempMat[row][col]]->c = col;
        }
      }
    }
  }

  cout << ans << "\n";

  return 0;
}