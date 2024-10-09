#include <bits/stdc++.h>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int r, c;
int width;

int bfs(vector<vector<int>> &mat, int row, int col) {
  int size = 1;
  queue<pair<int, int>> q;
  q.push({row, col});
  mat[row][col]++;

  while (!q.empty()) {
    auto curr = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nr = curr.first + dr[i];
      int nc = curr.second + dc[i];

      if (nr < 0 || nr >= r || nc < 0 || nc >= c)
        continue;
      if (mat[nr][nc] == 1) {
        q.push({nr, nc});
        mat[nr][nc]++;
        size++;
      }
    }
  }

  return size;
}

int main(int argc, char *argv[]) {
  cin >> width >> r >> c;

  vector<vector<int>> mat(r, vector<int>(c));
  vector<int> rooms;

  string tmp;
  for (int i = 0; i < r; ++i) {
    cin >> tmp;
    for (int j = 0; j < c; ++j) {
      if (tmp[j] == 'I') {
        mat[i][j] = 0;
      } else {
        mat[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (mat[i][j] == 1) {
        rooms.push_back(bfs(mat, i, j));
      }
    }
  }

  int room_count = 0;
  sort(rooms.begin(), rooms.end(), greater<int>());
  for (int i = 0; i < rooms.size(); ++i) {
    if (rooms[i] > width)
      break;
    else {
      room_count++;
      width -= rooms[i];
    }
  }

  if (room_count == 1) {
    cout << room_count << " room, " << width << " square metre(s) left over\n";
  } else {
    cout << room_count << " rooms, " << width << " square metre(s) left over\n";
  }
  return 0;
}