class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        int TOP = 0;
        int BOTTOM = n + 1;

        parent.resize(n + 2);
        sz.resize(n + 2, 1);

        for (int i = 0; i <= n + 1; i++)
            parent[i] = i;

        vector<vector<int>> grid(row, vector<int>(col, 0));

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int i = cells.size() - 1; i >= 0; i--) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;

            int id = r * col + c + 1;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc]) {
                    int nid = nr * col + nc + 1;
                    unite(id, nid);
                }
            }

            if (r == 0) unite(id, TOP);
            if (r == row - 1) unite(id, BOTTOM);

            if (find(TOP) == find(BOTTOM)) {
                return i;
            }
        }

        return 0;
    }
};