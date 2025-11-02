#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
   public:
    int m, n;
    int propagate(int r, int c, vector<vector<int>>& mat) {
        int res = 0;
        int dr = 1;
        while (r + dr < m) {
            if (mat[r + dr][c] == 0) {
                mat[r + dr][c] = 1;
                res++;
            } else if (mat[r + dr][c] > 1)
                break;
            dr++;
        }
        dr = -1;
        while (r + dr >= 0) {
            if (mat[r + dr][c] == 0) {
                mat[r + dr][c] = 1;
                res++;
            } else if (mat[r + dr][c] > 1)
                break;
            dr--;
        }

        int dc = 1;
        while (c + dc < n) {
            if (mat[r][c + dc] == 0) {
                mat[r][c + dc] = 1;
                res++;
            } else if (mat[r][c + dc] > 1)
                break;
            dc++;
        }
        dc = -1;
        while (c + dc >= 0) {
            if (mat[r][c + dc] == 0) {
                mat[r][c + dc] = 1;
                res++;
            } else if (mat[r][c + dc] > 1)
                break;
            dc--;
        }

        return res;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        this->m = m;
        this->n = n;
        vector<vector<int>> mat(m, vector<int>(n));
        for (const auto& guard : guards) {
            mat[guard[0]][guard[1]] = 2;
        }

        for (const auto& wall : walls) {
            mat[wall[0]][wall[1]] = 3;
        }

        int ans = m * n - guards.size() - walls.size();
        for (const auto& guard : guards) {
            ans -= propagate(guard[0], guard[1], mat);
        }

        return ans;
    }
};