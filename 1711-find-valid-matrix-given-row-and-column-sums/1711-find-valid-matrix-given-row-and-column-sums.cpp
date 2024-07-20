class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r = rowSum.size();
        int c = colSum.size();
        vector<vector<int>> mat(r, vector<int>(c, 0));

        for(int i = 0, j = 0; i < r && j < c; i += (rowSum[i] == 0), j += (colSum[j] == 0)) {
            int x = min(rowSum[i], colSum[j]);
            mat[i][j] = x;
            rowSum[i] -= x;
            colSum[j] -= x;
        }
        return mat;
    }
};