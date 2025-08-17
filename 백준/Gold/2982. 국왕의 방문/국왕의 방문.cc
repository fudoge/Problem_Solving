#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b, k, g;
    cin >> a >> b >> k >> g;
    --a;
    --b;

    vector<int> must(g);
    for (int i = 0; i < g; i++) {
        cin >> must[i];
        --must[i];
    }

    vector<vector<array<int, 3>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, L;
        cin >> u >> v >> L;
        --u;
        --v;
        adj[u].push_back({v, L, i});
        adj[v].push_back({u, L, i});
    }

    vector<int> blockStart(m, -1), blockEnd(m, -1);

    int t = 0;
    for (int i = 0; i < g - 1; i++) {
        int u = must[i], v = must[i + 1];

        int eid = -1, w = -1;
        for (const auto &e : adj[u]) {
            if (e[0] == v) {
                eid = e[2];
                w = e[1];
                break;
            }
        }

        blockStart[eid] = t;
        blockEnd[eid] = t + w;
        t += w;
    }

    vector<int> dist(n, 1e9);
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[a] = k;
    pq.emplace(k, a);

    while (!pq.empty()) {
        auto [currTime, currNode] = pq.top();
        pq.pop();

        if (currTime > dist[currNode]) continue;

        for (const auto &next : adj[currNode]) {
            int nextNode = next[0];
            int weight = next[1];
            int pathId = next[2];

            int depart = currTime;

            if (blockStart[pathId] != -1 && currTime >= blockStart[pathId] &&
                currTime < blockEnd[pathId]) {
                depart = blockEnd[pathId];
            }

            int nextDist = depart + weight;
            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.emplace(nextDist, nextNode);
            }
        }
    }

    cout << dist[b] - k << "\n";

    return 0;
}
