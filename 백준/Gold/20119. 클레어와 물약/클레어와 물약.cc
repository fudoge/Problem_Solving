#include <bits/stdc++.h>

using namespace std;

int n, m;
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<vector<set<int>>> recipes(n + 1);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        set<int> s;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        int dst;
        cin >> dst;
        for (const auto &src : s) {
            adj[src].emplace_back(dst);
        }
        recipes[dst].emplace_back(s);
    }

    int startSize;
    cin >> startSize;
    vector<bool> visited(n + 1, false);
    queue<int> q;
    for (int i = 0; i < startSize; i++) {
        int x;
        cin >> x;
        q.emplace(x);
        visited[x] = true;
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (const auto &next : adj[curr]) {
            if (visited[next]) continue;
            for (auto &s : recipes[next]) {
                s.erase(curr);
                if (s.empty()) {
                    visited[next] = true;
                    q.emplace(next);
                    break;
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) ans.emplace_back(i);
    }

    cout << ans.size() << "\n";
    for (const auto &elem : ans) cout << elem << " ";
    cout << "\n";

    return 0;
}