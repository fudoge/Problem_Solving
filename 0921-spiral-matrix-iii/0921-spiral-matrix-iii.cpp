class Solution {
public:
    bool isInMatrix(int currRow, int currCol, int rows, int cols) {
        return currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int leftBox = (rows * cols) - 1;
        int currRow = rStart, currCol = cStart;
        int moveRange = 1;
        ans.push_back({currRow, currCol});
        while(leftBox > 0) {
            // move Right
            for(int i = 0; i < moveRange; i++) {
                currCol++;
                if(isInMatrix(currRow, currCol, rows, cols)) {
                    ans.push_back({currRow, currCol});
                    if(--leftBox <= 0) return ans;
                }
            }

            // move Down
            for(int i = 0; i < moveRange; i++) {
                currRow++;
                if(isInMatrix(currRow, currCol, rows, cols)) {
                    ans.push_back({currRow, currCol});
                    if(--leftBox <= 0) return ans;
                }
            }

            moveRange++;

            // move Left
            for(int i = 0; i < moveRange; i++) {
                currCol--;
                if(isInMatrix(currRow, currCol, rows, cols)) {
                    ans.push_back({currRow, currCol});
                    if(--leftBox <= 0) return ans;
                }
            }

            // move Up
            for(int i = 0; i < moveRange; i++) {
                currRow--;
                if(isInMatrix(currRow, currCol, rows, cols)) {
                    ans.push_back({currRow, currCol});
                    if(--leftBox <= 0) return ans;
                }
            }
            
            moveRange++;
        }

        return ans;
    }
};