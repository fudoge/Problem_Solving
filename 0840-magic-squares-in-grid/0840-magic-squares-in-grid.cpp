class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < m - 2; j++) {
                long long mask = 0;
                for(int r = 0; r < 3; r++) {
                    for(int c = 0; c < 3; c++) {
                        mask |= (1 << grid[i+r][j+c]);
                    }
                }
                bool flag = true;
                for(int k = 1; k <= 9; k++) {
                    if(!(mask & (1 << k))) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) continue;

                int x1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                int x2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
                int x3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                int y1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
                int y2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
                int y3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
                int z1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int z2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
                if(x1 == x2 && x1 == x3 && x1 == y1 && x1 == y2 && x1 == y3 && x1 == z1 && x1 == z2) {
                    ans++;
                }
            }
        }     

        return ans;
    }
};