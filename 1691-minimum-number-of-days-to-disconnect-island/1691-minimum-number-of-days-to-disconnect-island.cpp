class Solution {
private:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int m, n;
public:
    vector<int> traverse(vector<vector<int>> &grid) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> res;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    int size = 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                            if(!grid[nx][ny]) continue;
                            if(visited[nx][ny]) continue;
                            
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                            size++;
                        }
                    }
                    res.push_back(size);
                }
            }
        }
        return res;
    }
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<int> islands = traverse(grid);

        if(islands.size() != 1) return 0;
        if(islands.size() == 1 && islands[0] == 1) return 1;
        if(islands.size() == 1 && islands[0] == 2) return 2;

        int ans = INT_MAX;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int change = 0;
                    for(int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                            change++;
                        }
                    }
                    ans = min(ans, change);

                    grid[i][j] = 0;
                    auto islandsWithPunch = traverse(grid);
                    grid[i][j] = 1;
                    if(islandsWithPunch.size() != 1) return 1;
                }
            }
        }

        return ans;
    }
};