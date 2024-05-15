class Solution {
private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& score, int n) {
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    score[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int s = score[curr.first][curr.second];

            for(int i = 0; i < 4; i++) {
                int nx = curr.first + dx[i];
                int ny = curr.second + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n && score[nx][ny] > s+1) {
                    score[nx][ny] = s+1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] || grid[n-1][n-1]) return 0;

        vector<vector<int>> score(n, vector<int>(n, 1e9));
        bfs(grid, score, n);
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({score[0][0], {0, 0}});

        while(!pq.empty()) {
            auto curr = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();

            if(curr.first == n-1 && curr.second == n-1) return safe;
            visited[curr.first][curr.second] = true;

            for(int i = 0; i < 4; i++) {
                int nx = curr.first + dx[i];
                int ny = curr.second + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    int s = min(safe, score[nx][ny]);
                    pq.push({s, {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }

        return -1;
    }
};