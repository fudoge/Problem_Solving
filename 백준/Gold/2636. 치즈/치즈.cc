#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<bitset<100>> mat(100);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            mat[i][j] = temp & 1;
        }
    }

    int last_cnt = 0;
    int time = 0;
    while (true) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt += mat[i][j];
            }
        }

        if (cnt == 0) break;
        last_cnt = cnt;

        vector<bitset<100>> flip(100);
        vector<bitset<100>> visited(100);
        for (int i = 0; i < 100; i++) {
            flip[i].reset();
            visited[i].reset();
        }

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visited[0][0] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (~mat[nx][ny] && ~visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.emplace(nx, ny);
                } else if (mat[nx][ny]) {
                    flip[nx][ny] = 1;
                }
            }
        }

        for (int i = 0; i < 100; i++) mat[i] ^= flip[i];
        time++;
    }

    cout << time << "\n";
    cout << last_cnt << "\n";

    return 0;
}