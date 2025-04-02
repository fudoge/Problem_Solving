#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using tiii = tuple<int, int, int>;
class Solution {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

   public:
    vector<int> calc(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        int maxElem = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > maxElem) maxElem = grid[i][j];
            }
        }
        vector<int> sizes(maxElem + 1);

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<tiii, vector<tiii>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        visited[0][0] = true;
        int currMaxNum = 0;
        while (!pq.empty()) {
            int num, x, y;
            tie(num, x, y) = pq.top();
            pq.pop();

            int maxNum = max(num, currMaxNum);

            while (currMaxNum < maxNum) {
                sizes[currMaxNum + 1] = sizes[currMaxNum];
                currMaxNum++;
            }
            sizes[currMaxNum]++;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) {
                    continue;
                }
                pq.emplace(grid[nx][ny], nx, ny);
                visited[nx][ny] = true;
            }
        }

        return sizes;
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> sizes = calc(grid, queries);
        vector<int> res;
        int l = sizes.size();

        for (const auto& query : queries) {
            res.emplace_back(sizes[min(query - 1, l-1)]);
        }

        return res;
    }
};