int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0 && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    long long sum = grid[i][j];
                    while(!q.empty()) {
                        auto curr = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int nr = curr.first + dr[k];
                            int nc = curr.second + dc[k];

                            if(nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc] || !grid[nr][nc]) {
                                continue;
                            }

                            sum += grid[nr][nc];
                            q.push({nr, nc});
                            visited[nr][nc] = true;
                        }
                    }

                    if(sum % k == 0) ans++;
                }
            }
        }

        return ans;
    }
};

//  0  0  4 0
//  0  0 14 0
//  0  0  0 0
// 10  2  0 0
//  0 20  0 0