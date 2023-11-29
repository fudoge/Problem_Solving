#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<int> table;


void bfs(pair<int, int> start, vector<vector<int>> &land, vector<vector<bool>> &visited) {
    const int n = land.size();
    const int m = land[0].size();
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    int cnt = 0;

    set<int> cols;

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        cols.insert(y);
        cnt++;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(visited[nx][ny]) continue;
            if(!land[nx][ny]) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    for(const auto &col : cols) {
        table[col] += cnt;
    }
}

int solution(vector<vector<int>> land) {
    const int n = land.size();
    const int m = land[0].size();
    table.resize(m);
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(land[i][j] && !visited[i][j]) {
                bfs({i, j}, land, visited);
            }
        }
    }

    return *max_element(table.begin(), table.end());
}