class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int j = 0;
        while(j < m && grid[0][j] >= 0) {
            j++; 
        }

        int ans = m - j;
        for(int i = 1; i < n; i++) {
            while(j > 0 && grid[i][j-1] < 0) {
                j--;
            }
            ans += m - j;
        }
         
        return ans;
    }
};

//  4  3  2 -1
//  3  2  1 -1
//  1  1 -1 -2
// -1 -1 -2 -3