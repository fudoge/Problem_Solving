class Solution {
private:
    int m, n;
public:
    bool isMinima(int row, int col, vector<vector<int>>& matrix) {
        int maxIdx = 0;
        int maximum = matrix[0][col];
        for(int i = 1; i < m; i++) {
            if(maximum < matrix[i][col]) {
                maxIdx = i;
                maximum = matrix[i][col];
            }
        }

        return maxIdx == row;
    }

    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        m = matrix.size();
        n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            int minIdx = 0;
            int minimum = matrix[i][0];
            for(int j = 1; j < n; j++) {
                if(minimum > matrix[i][j]) {
                    minIdx = j;
                    minimum = matrix[i][j];
                }
            }
            if(isMinima(i, minIdx, matrix)) ans.push_back(minimum);
        }

        return ans;
    }
};

// 3 7 8
// 9 11 13
// 15 16 17