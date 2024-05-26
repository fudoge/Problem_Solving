class Solution {
public:
    int check(vector<vector<int>> &mat, int row, int col) {
        int mask = 0;
        for(int i = 0; i < mat.size(); i++) {
            if(i == row) continue;
            mask |= mat[i][col];
            if(mask) return 0;
        }

        for(int j = 0; j < mat[0].size(); j++) {
            if(j == col) continue;
            mask |= mat[row][j];
            if(mask) return 0;
        }

        return 1;
    }

    int numSpecial(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        int cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    cnt += check(mat, i, j);
                }
            }
        }

        return cnt;
    }
};