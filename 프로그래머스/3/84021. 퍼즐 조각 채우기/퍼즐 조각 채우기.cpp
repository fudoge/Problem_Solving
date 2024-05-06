#include <bits/stdc++.h>

using namespace std;

int n;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

bool isMatch(vector<int> &a, vector<int> &b, vector<vector<int>> &table, vector<vector<int>> &game_board) {
    int a_height = a[2] - a[0];
    int a_width = a[3] - a[1];
    int b_height = b[2] - b[0];
    int b_width = b[3] - b[1];

    if (a_height == b_height && a_width == b_width) {
        // 0, 180
        // 0
        bool flag = true;
        for (int i = 0; i <= a_height; i++) {
            for (int j = 0; j <= a_width; j++) {
                if (!(table[a[0] + i][a[1] + j] ^ game_board[b[0] + i][b[1] + j])) {
                    flag = false;
                }
            }
        }
        if (flag) return true;

        // 180
        flag = true;
        for (int i = 0; i <= a_height; i++) {
            for (int j = 0; j <= a_width; j++) {
                if (!(table[a[2] - i][a[3] - j] ^ game_board[b[0] + i][b[1] + j])) {
                    flag = false;
                }
            }
        }

        if(flag) return true;
    }
    if (a_height == b_width && a_width == b_height) {
        // 90, 270
        // 90
        bool flag = true;
        for (int i = 0; i <= a_width; i++) {
            for (int j = 0; j <= a_height; j++) {
                if (!(table[a[2] - j][a[1] + i] ^ game_board[b[0] + i][b[1] + j])) {
                    flag = false;
                }
            }
        }
        if (flag) return true;

        // 270
        for (int i = 0; i <= a_width; i++) {
            for (int j = 0; j <= a_height; j++) {
                if (!(table[a[0] + j][a[3] - i] ^ game_board[b[0] + i][b[1] + j])) {
                    return false;
                }
            }
        }
        return true;
    } else return false;
}

vector<int> bfs(int row, int col, int target, vector<vector<bool>> &visited, vector<vector<int>> &table) {
    vector<int> res = {n + 1, n + 1, -1, -1, 0};
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        res[0] = min(res[0], curr.first);
        res[1] = min(res[1], curr.second);
        res[2] = max(res[2], curr.first);
        res[3] = max(res[3], curr.second);
        res[4]++;

        for (int i = 0; i < 4; i++) {
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (!visited[nr][nc] && table[nr][nc] == target) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    return res;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    n = table.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    // [topleft_row, topleft_col, bottomright_row, bottomright_col, size]
    vector<vector<int>> fragments;
    // 빈 공간
    vector<vector<int>> board_empty;

    // 테이블 조각부터 찾자...
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && table[i][j] == 1) {
                fragments.push_back(bfs(i, j, 1, visited, table));
            }
        }
    }

    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && game_board[i][j] == 0)
                board_empty.push_back(bfs(i, j, 0, visited, game_board));
        }
    }

    for (auto fragment : fragments) {
        for (int i = 0; i < board_empty.size(); i++) {
            if (fragment[4] == board_empty[i][4]) {
                if (isMatch(fragment, board_empty[i], table, game_board)) {
                    board_empty.erase(board_empty.begin() + i);
                    answer += fragment[4];
                    break;
                }
            }
        }
    }

    return answer;
}