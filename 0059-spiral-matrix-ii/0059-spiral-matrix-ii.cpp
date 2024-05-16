class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix (n, vector<int>(n, 1));
        if(n == 1){
            return matrix;
        }
        int goal = n * n;
        int col = 0;
        int row = 0;
        int cnt = 1;
        int loop = 0;

        while(cnt < goal){
            row++;
            for(int i = row; i < n; i++){
                matrix.at(col).at(i) += cnt;
                cnt++;
            }
            if(cnt >= goal) break;
            col++;
            row = n-1;
            for(int i = col; i < n; i++){
                matrix.at(i).at(row) += cnt;
                cnt++;
            }
            if(cnt >= goal) break;
            row--;
            col = n-1;
            n--;
            for(int i = row; i >= loop; i--){
                matrix.at(col).at(i) += cnt;
                cnt++;
            }
            if(cnt >= goal) break;
            col--;
            row = loop;
            loop++;
            for(int i = col; i >= loop; i--){
                matrix.at(i).at(row) += cnt;
                cnt++;
            }
            col = loop;
        }
        return matrix;
    }
};