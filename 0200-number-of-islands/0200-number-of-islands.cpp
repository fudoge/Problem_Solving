#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int di[] = {1, -1, 0, 0};
        int dj[] = {0, 0, 1, -1};

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    q.push({i, j});
                    visited[i][j] = true;

                    while(!q.empty()) {
                        auto curr = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int ni = curr.first + di[k];
                            int nj = curr.second + dj[k];

                            if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1' && !visited[ni][nj]) {
                                q.push({ni, nj});
                                visited[ni][nj] = true;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};