#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
   public:
    int getRoot(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = getRoot(parent[x], parent);
    }
    void merge(int x, int y, vector<int>& parent) {
        int xRoot = getRoot(x, parent);
        int yRoot = getRoot(y, parent);
        if (xRoot == yRoot) return;
        if (xRoot < yRoot) {
            parent[yRoot] = xRoot;
        } else {
            parent[xRoot] = yRoot;
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<int> parent(c + 1, 0);
        vector<bool> alive(c + 1, 1);
        iota(parent.begin(), parent.end(), 0);
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> grids;

        for (const auto& con : connections) {
            int a = con[0];
            int b = con[1];

            merge(a, b, parent);
        }

        for (int i = 1; i <= c; i++) {
            int root = getRoot(i, parent);
            grids[root].emplace(i);
        }

        vector<int> ans;
        for (const auto& query : queries) {
            int op = query[0];
            int x = query[1];

            if (op == 1) {
                if (alive[x]) {
                    ans.emplace_back(x);
                } else {
                    int root = getRoot(x, parent);
                    while (!grids[root].empty() &&
                           alive[grids[root].top()] == false) {
                        grids[root].pop();
                    }
                    if (grids[root].empty()) {
                        ans.emplace_back(-1);
                    } else {
                        ans.emplace_back(grids[root].top());
                    }
                }
            } else {
                alive[x] = false;
            }
        }

        return ans;
    }
};