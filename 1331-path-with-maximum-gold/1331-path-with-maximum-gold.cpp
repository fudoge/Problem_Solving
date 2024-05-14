#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

class Solution {
private:
    int maxGold;
    int m;
    int n;
public:
    void dfs(int sum, int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        sum += grid[row][col];
        maxGold = max(maxGold, sum);
        visited[row][col] = true;
        for(int i = 0; i < 4; i++) {
            int nr = dr[i] + row;
            int nc = dc[i] + col;

            if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if(visited[nr][nc]) continue;
            if(!grid[nr][nc]) continue;
            dfs(sum, nr, nc, visited, grid);
        }

        visited[row][col] = false;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        maxGold = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    dfs(0, i, j, visited, grid);
                }
            }
        }

        return maxGold;
    }
};