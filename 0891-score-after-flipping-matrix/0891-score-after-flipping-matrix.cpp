class Solution {
private:
    int n, m;
public:
    void flipCol(int col, vector<vector<int>> &grid) {
        for(int i = 0; i < m; i++) {
            grid[i][col] ^= 1;
        }
    }
    void flipRow(int row, vector<vector<int>> &grid) {
        for(int i = 0; i < n; i++) {
            grid[row][i] ^= 1;
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        n = grid[0].size();
        m = grid.size();

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) {
                flipRow(i, grid);
            }
        }

        for(int j = 1; j < n; j++) {
            int cnt = 0;
            for(int i = 0; i < m; i++) {
                cnt += grid[i][j];
            }
            if(cnt <= m/2) {
                flipCol(j, grid);
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++) {
            int num = 0;
            for(int j = 0; j < n; j++) {
                num += grid[i][j] * static_cast<double>(pow(2, n-j-1));
            }
            cout << num << endl;
            ans += num;
        }


        return ans;
    }
};