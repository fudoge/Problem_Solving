#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
    }

    int x;
    int ans = 0;
    cin >> x;
    queue<int> q;
    q.emplace(x);
    visited[x] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (const auto &elem : adj[curr]) {
            if (!visited[elem]) {
                visited[elem] = true;
                q.emplace(elem);
                ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
