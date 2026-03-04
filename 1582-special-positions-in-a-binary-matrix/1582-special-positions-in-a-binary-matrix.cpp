class Solution {
public:
    int check(int i, int j, vector<vector<int>>& mat) {
        int cnt = 0;
        for(int r = 0; r < mat.size(); r++) {
            cnt += mat[r][j];
        }
        if(cnt != 1) return 0;
        for(int c = 0; c < mat[0].size(); c++) {
            cnt += mat[i][c];
        }
        if(cnt != 2) return 0;
        return 1; 
    }
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int ans = 0;
        vector<bool> cok(n, false);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(cok[j]) continue;
                if(mat[i][j]) {
                    ans += check(i, j, mat);
                    cok[j] = true;
                    break;
                }
            }
        }
        return ans;
    }
};