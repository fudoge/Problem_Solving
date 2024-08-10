class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    
    void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<int> parent(4 * n * n);
        vector<int> rank(4 * n * n, 0);
        
        for (int i = 0; i < 4 * n * n; i++) {
            parent[i] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int index = 4 * (i * n + j);
                char val = grid[i][j];
                
                if (val == '/') {
                    unite(parent, rank, index + 0, index + 3);
                    unite(parent, rank, index + 1, index + 2);
                } else if (val == '\\') {
                    unite(parent, rank, index + 0, index + 1);
                    unite(parent, rank, index + 2, index + 3);
                } else {
                    unite(parent, rank, index + 0, index + 1);
                    unite(parent, rank, index + 1, index + 2);
                    unite(parent, rank, index + 2, index + 3);
                }
                
                if (i > 0) {
                    unite(parent, rank, index + 0, (index - 4 * n) + 2);
                }
                if (j > 0) {
                    unite(parent, rank, index + 3, (index - 4) + 1);
                }
            }
        }
        
        int regions = 0;
        for (int i = 0; i < 4 * n * n; i++) {
            if (find(parent, i) == i) {
                regions++;
            }
        }
        
        return regions;
    }
};