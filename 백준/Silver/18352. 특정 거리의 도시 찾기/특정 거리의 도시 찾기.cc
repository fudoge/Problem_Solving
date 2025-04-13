#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, x;
    cin >> n >> m >> k >> x;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }

    vector<int> dist(n + 1, INT_MAX);
    queue<int> q;
    dist[x] = 0;
    q.emplace(x);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (const auto &next : adj[curr]) {
            if (dist[next] > dist[curr] + 1) {
                dist[next] = dist[curr] + 1;
                q.emplace(next);
            }
        }
    }

    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            flag = true;
            cout << i << "\n";
        }
    }
    if (!flag) cout << "-1\n";
    return 0;
}