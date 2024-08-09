#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool isMagicSquare(int r, int c, vector<vector<int>>& grid) {
        vector<bool> table(9, false);
        vector<int> sums(8, 0);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int val = grid[i+r][j+c];
                if(val < 1 || val > 9) return false;
                if(table[val-1]) return false;
                table[val-1] = true;
                sums[i] += val;
                sums[3+j] += val;
            }
        }
        sums[6] = grid[r][c] + grid[r+2][c+2] + grid[r+1][c+1];
        sums[7] = grid[r][c+2] + grid[r+2][c] + grid[r+1][c+1];

        for(int i = 1; i < 8; i++) {
            if(sums[0] != sums[i]) return false;
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n-2; i++) {
            for(int j = 0; j < m-2; j++) {
                if(isMagicSquare(i, j, grid)) ans++;
            }
        }

        return ans;
    }
};