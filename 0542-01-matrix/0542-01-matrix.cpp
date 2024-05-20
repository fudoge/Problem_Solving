class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<vector<int>> q;

        vector<vector<int>> table (m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    table[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while(!q.empty()) {
            int a = q.front()[0];
            int b = q.front()[1];
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = a + dx[i];
                int y = b + dy[i];

                if (0 <= x && x < m && 0 <= y && y < n && table[x][y] == -1 && mat[x][y] == 1) {
                    table[x][y] = table[a][b] + 1;
                    q.push({x, y});
                }
            }
        }
        return table;
    }

};