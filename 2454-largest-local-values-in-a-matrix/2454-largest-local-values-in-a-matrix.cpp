class Solution {
public:
    int getMax(int i, int j, vector<vector<int>>& grid ) {
        int maxVal = -1e9;
        for(int row = i-1; row <= i+1; row++) {
            for(int col = j-1; col <= j+1; col++) {
                maxVal = max(maxVal, grid[row][col]);
            }
        }

        return maxVal;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans (n-2, vector<int>(n-2, -1e9));

        for(int i = 1; i < n-1; i++) {
            for(int j = 1; j < n-1; j++) {
                ans[i-1][j-1] = getMax(i, j, grid);
            }
        }

        return ans;
    }
};