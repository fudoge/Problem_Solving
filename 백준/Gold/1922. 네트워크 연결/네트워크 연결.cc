#include <bits/stdc++.h>

using namespace std;
using tiii = tuple<int, int, int>;

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

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<tiii> edges;
    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges.emplace_back(w, u, v);
    }

    sort(edges.begin(), edges.end());
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int w, u, v;
        tie(w, u, v) = edges[i];

        if (getRoot(u, parent) == getRoot(v, parent)) {
            continue;
        }

        merge(u, v, parent);
        ans += w;
    }

    cout << ans << "\n";

    return 0;
}