#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

vector<int> parent, depth, head, heavy, pos;
vector<int> seg, base;
int cur_pos, n;

int dfs(int v, const vector<vector<int>>& adj) {
    int size = 1;
    int max_c_size = 0;

    for (int c : adj[v]) {
        if (c == parent[v]) continue;

        parent[c] = v;
        depth[c] = depth[v] + 1;

        int c_size = dfs(c, adj);
        size += c_size;

        if (c_size > max_c_size) {
            max_c_size = c_size;
            heavy[v] = c;
        }
    }

    return size;
}

void decompose(int v, int h,
               const vector<vector<int>>& adj) {
    head[v] = h;
    pos[v] = cur_pos++;

    if (heavy[v] != -1) {
        decompose(heavy[v], h, adj);
    }

    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v]) {
            decompose(c, c, adj);
        }
    }
}

void seg_init(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = 1 << base[l];
        return;
    }

    int mid = (l + r) >> 1;

    seg_init(idx * 2, l, mid);
    seg_init(idx * 2 + 1, mid + 1, r);

    seg[idx] = seg[idx * 2] ^ seg[idx * 2 + 1];
}

int seg_query(int idx, int ql, int qr,
              int l, int r) {
    if (qr < l || ql > r) return 0;

    if (ql <= l && r <= qr)
        return seg[idx];

    int mid = (l + r) >> 1;

    return seg_query(idx * 2, ql, qr, l, mid)
         ^ seg_query(idx * 2 + 1, ql, qr, mid + 1, r);
}

void seg_update(int idx, int p, int value,
                int l, int r) {
    if (l == r) {
        seg[idx] = 1 << value;
        return;
    }

    int mid = (l + r) >> 1;

    if (p <= mid)
        seg_update(idx * 2, p, value, l, mid);
    else
        seg_update(idx * 2 + 1, p, value, mid + 1, r);

    seg[idx] = seg[idx * 2] ^ seg[idx * 2 + 1];
}

void init(const vector<vector<int>>& adj,
          const string& s) {
    n = adj.size();

    parent.assign(n, -1);
    depth.assign(n, 0);
    head.assign(n, 0);
    heavy.assign(n, -1);
    pos.assign(n, 0);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);

    base.resize(n);
    for (int u = 0; u < n; ++u) {
        base[pos[u]] = s[u] - 'a';
    }

    seg.assign(4 * n, 0);
    seg_init(1, 0, n - 1);
}

int query(int a, int b) {
    int res = 0;

    while (head[a] != head[b]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);

        res ^= seg_query(
            1, pos[head[b]], pos[b], 0, n - 1
        );

        b = parent[head[b]];
    }

    if (depth[a] > depth[b])
        swap(a, b);

    res ^= seg_query(1, pos[a], pos[b], 0, n - 1);

    return res;
}

void update(int u, char ch) {
    seg_update(1, pos[u], ch - 'a', 0, n - 1);
}

class Solution {
public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        init(adj, s);

        vector<bool> ans;

        for (const auto& q : queries) {
            stringstream ss(q);

            string op;
            int u;
            ss >> op >> u;

            if (op == "query") {
                int v;
                ss >> v;

                int mask = query(u, v);
                ans.push_back(
                    __builtin_popcount(
                        static_cast<unsigned>(mask)
                    ) <= 1
                );
            } else {
                char ch;
                ss >> ch;

                update(u, ch);
            }
        }

        return ans;
    }
};
