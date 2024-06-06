#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int di[] = {1, -1, 0, 0};
        int dj[] = {0, 0, 1, -1};
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m ; j++) {
                if(land[i][j] == 1 && !visited[i][j]) {
                    vector<int> group = {i, j, i, j};
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while(!q.empty()) {
                        auto curr = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int ni = curr.first + di[k];
                            int nj = curr.second + dj[k];

                            if(ni < 0 || ni >= n || nj < 0 || nj >= m || !land[ni][nj] || visited[ni][nj]) continue;
                            q.push({ni, nj});
                            visited[ni][nj] = true;
                            if(group[2] < ni) group[2] = ni;
                            if(group[3] < nj) group[3] = nj;
                        }
                    }
                    ans.push_back(group);
                }
            }
        }

        return ans;
    }
};