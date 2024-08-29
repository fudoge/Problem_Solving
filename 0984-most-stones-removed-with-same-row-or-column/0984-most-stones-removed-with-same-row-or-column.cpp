class Union {
public:
    vector<int> rank, parent;
    Union(int n) {
        rank.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int u, int v) {
        int uRoot = find(u);
        int vRoot = find(v);

        if(uRoot == vRoot) return;
        if(rank[uRoot] < rank[vRoot]) {
            parent[uRoot] = vRoot;
            rank[vRoot] += rank[uRoot];
        } else {
            parent[vRoot] = uRoot;
            rank[uRoot] += rank[vRoot];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int rMax = 0;
        int cMax = 0;

        for(const auto &stone : stones) {
            rMax = max(rMax, stone[0]);
            cMax = max(cMax, stone[1]);
        }

        Union u(rMax+cMax+1);
        unordered_map<int, int> mp;

        for(auto &stone : stones) {
            int row = stone[0];
            int col = stone[1] + rMax + 1;

            u.unionSet(row, col);
            mp[row] = 1;
            mp[col] = 1;
        }

        int cnt = 0;
        for(const auto &element : mp) {
            if(u.find(element.first) == element.first) cnt++;
        }

        return n-cnt;
    }
};