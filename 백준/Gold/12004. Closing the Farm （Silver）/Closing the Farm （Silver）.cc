#include <bits/stdc++.h>

using namespace std;

int n, m;

bool bfs(int start, vector<vector<int>>& adj, vector<bool>& banned) {
    vector<bool> visited(n + 1);
    queue<int> q;
    q.emplace(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (const auto& next : adj[curr]) {
            if (banned[next]) continue;
            if (!visited[next]) {
                q.emplace(next);
                visited[next] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!banned[i] && !visited[i]) return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> del(n);
    for (auto& i : del) cin >> i;

    vector<bool> banned(n + 1);
    int start = 1;
    for (int i = 0; i < n; i++) {
        if (bfs(start, adj, banned)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        banned[del[i]] = true;
        if (del[i] == start) {
            while (banned[start]) {
                start++;
            }
        }
    }

    return 0;
}
