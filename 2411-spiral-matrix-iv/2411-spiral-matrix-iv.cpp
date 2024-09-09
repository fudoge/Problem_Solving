#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int rowStart = 0, rowEnd = m - 1;
        int colStart = 0, colEnd = n - 1;
        
        while (head && rowStart <= rowEnd && colStart <= colEnd) {
            for (int col = colStart; col <= colEnd && head; ++col) {
                ans[rowStart][col] = head->val;
                head = head->next;
            }
            rowStart++;
            
            for (int row = rowStart; row <= rowEnd && head; ++row) {
                ans[row][colEnd] = head->val;
                head = head->next;
            }
            colEnd--;
            
            for (int col = colEnd; col >= colStart && head; --col) {
                ans[rowEnd][col] = head->val;
                head = head->next;
            }
            rowEnd--;
            
            for (int row = rowEnd; row >= rowStart && head; --row) {
                ans[row][colStart] = head->val;
                head = head->next;
            }
            colStart++;
        }
        
        return ans;
    }
};