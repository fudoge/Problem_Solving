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
    bool dfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if(r < 0 || r >= m || c < 0 || c >= n || grid2[r][c] == 0) return true;
        bool flag = grid1[r][c] == 1;
        grid2[r][c] = 0;
        flag &= dfs(r-1, c, grid1, grid2);
        flag &= dfs(r+1, c, grid1, grid2);
        flag &= dfs(r, c-1, grid1, grid2);
        flag &= dfs(r, c+1, grid1, grid2);


        return flag;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid1[i][j] && grid2[i][j]) {
                    if(dfs(i, j, grid1, grid2)) ans++;
                }
            }
        }
        
        return ans;
    }
};