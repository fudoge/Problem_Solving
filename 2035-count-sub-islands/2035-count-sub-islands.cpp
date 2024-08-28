#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
private:
    int m;
    int n;
    vector<int> dx;
    vector<int> dy;
    bool bfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        bool flag = true;
        queue<pair<int, int>> q;
        q.push({r, c});

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(grid2[nx][ny]) {
                    if(!grid1[nx][ny]) flag = false;
                    grid2[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }

        return flag;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        dx = {-1, 1, 0, 0};
        dy = {0, 0, -1, 1};
        
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid1[i][j] && grid2[i][j]) {
                    if(bfs(i, j, grid1, grid2)) ans++;
                }
            }
        }
        
        return ans;
    }
};