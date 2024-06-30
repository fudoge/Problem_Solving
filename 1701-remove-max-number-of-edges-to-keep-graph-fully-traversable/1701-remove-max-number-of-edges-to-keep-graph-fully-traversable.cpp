class UF {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UF(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if(rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool isTraversable(UF& uf, int n) {
        int root = uf.find(1);
        for(int i = 2; i <= n; i++) {
            if(uf.find(i) != root) {
                return false;
            }
        }
        return true;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        // union_find.
        UF union_Alice(n + 1);
        UF union_Bob(n + 1);

        sort(edges.begin(), edges.end(), [](const auto &a, const auto &b) {
            return a[0] > b[0];
        });

        for(const auto &edge : edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            if(type == 3) {
                if(union_Alice.unionSet(u, v) | union_Bob.unionSet(u, v)) {
                } else {
                    ans++;
                }
            } else if(type == 2) {
                if(!union_Bob.unionSet(u, v)) {
                    ans++;
                }
            } else if(type == 1) {
                if(!union_Alice.unionSet(u, v)) {
                    ans++;
                }
            }
        }

        if(!isTraversable(union_Alice, n) || !isTraversable(union_Bob, n)) {
            return -1;
        }

        return ans;
    }
};