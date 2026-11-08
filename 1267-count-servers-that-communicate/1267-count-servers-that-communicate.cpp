class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ans = 0;
        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    int found = 0;
                    while(!q.empty()) {
                        auto curr = q.front();
                        int r = curr.first;
                        int c = curr.second;
                        found++;
                        q.pop();

                        for(int nr = r+1; nr < m; nr++) {
                            if(grid[nr][c] && !visited[nr][c]) {
                                q.push({nr, c});
                                visited[nr][c] = true;
                            }
                        }

                        for(int nr = r-1; nr >= 0; nr--) {
                            if(grid[nr][c] && !visited[nr][c]) {
                                q.push({nr, c});
                                visited[nr][c] = true;
                            }
                        }

                        for(int nc = c+1; nc < n; nc++) {
                            if(grid[r][nc] && !visited[r][nc]) {
                                q.push({r, nc});
                                visited[r][nc] = true;
                            }
                        }

                        for(int nc = c-1; nc >= 0; nc--) {
                            if(grid[r][nc] && !visited[r][nc]) {
                                q.push({r, nc});
                                visited[r][nc] = true;
                            }
                        }
                    }

                    if(found > 1) ans += found;
                }
            }
        }       

        return ans;
    }
};