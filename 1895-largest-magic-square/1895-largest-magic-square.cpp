class Solution {
public:
    int m, n;
    bool check(vector<vector<vector<int>>>& pref, vector<vector<int>>& grid,
               int r, int c, int len) {
        int diag1 = 0, diag2 = 0;
        for (int i = 0; i < len; i++) {
            diag1 += grid[r + i][c + i];
            diag2 += grid[r + i][c + len - i - 1];
        }
        if (diag1 != diag2)
            return false;
        int sum = diag1;
        for (int i = r; i < r + len; i++) {
            int lineSum = c - 1 >= 0
                              ? pref[i][c + len - 1][0] - pref[i][c - 1][0]
                              : pref[i][c + len - 1][0];
            if (lineSum != sum)
                return false;
        }
        for (int j = c; j < c + len; j++) {
            int lineSum = r - 1 >= 0
                              ? pref[r + len - 1][j][1] - pref[r - 1][j][1]
                              : pref[r + len - 1][j][1];
            if (lineSum != sum)
                return false;
        }
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> pref(
            m, vector<vector<int>>(n, vector<int>(2)));

        for (int i = 0; i < m; i++) {
            pref[i][0][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                pref[i][j][0] = pref[i][j - 1][0] + grid[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            pref[0][j][1] = grid[0][j];
            for (int i = 1; i < m; i++) {
                pref[i][j][1] = pref[i - 1][j][1] + grid[i][j];
            }
        }
        int ans = 1;
        int maxCand = min(m, n);
        for (int k = 2; k <= maxCand; k++) {
            bool flag = false;
            for (int i = 0; i <= m - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (check(pref, grid, i, j, k)) {
                        ans = k;
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
        return ans;
    }
};