#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int bfs(vector<string>& maps, pair<int, int> from, pair<int, int> to) {
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    queue<pair<int, int>> q;
    visited[from.first][from.second] = true;
    q.push(from);

    int cnt = 0;
    while (!q.empty()) {
        int currentSize = q.size();
        for (int t = 0; t < currentSize; t++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < visited.size() && ny >= 0 && ny < visited[0].size()) {
                    if(nx == to.first && ny == to.second) return ++cnt;
                    if (maps[nx][ny] == 'X') continue;
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        cnt++;
    }

    return -1;
}


int solution(vector<string> maps) {
    pair<int, int> s; //출발점
    pair<int, int> l; //레버
    pair<int, int> e; //목적지

    for(int i = 0; i < maps.size(); i++) {
        for(int j = 0; j < maps[i].size(); j++) {
            if(maps[i][j] == 'S') {
                s = {i, j};
            } else if(maps[i][j] == 'L') {
                l = {i, j};
            } else if(maps[i][j] == 'E') {
                e = {i, j};
            }
        }
    }

    int to_lever = bfs(maps, s, l);
    if(to_lever == -1) return -1;
    int to_exit = bfs(maps, e, l);
    if(to_exit == -1) return -1;

    return to_lever + to_exit;
}