#include <bits/stdc++.h>

#include <climits>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using tlll = tuple<ll, ll, ll>;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> wtank(n);
    vector<vector<pll>> adj(n);
    for (auto &w : wtank) cin >> w;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int s, t;
    cin >> s >> t;
    s--;
    t--;

    vector<ll> dist(n, LLONG_MAX);
    vector<ll> gain(n, 0);
    dist[s] = 0;
    gain[s] = wtank[s];

    priority_queue<tlll, vector<tlll>, greater<>> pq;  // dist, gain, node;
    pq.emplace(dist[s], gain[s], s);

    while (!pq.empty()) {
        auto [currDist, currGain, currNode] = pq.top();
        pq.pop();

        if (currDist > dist[currNode] ||
            (currDist == dist[currNode] && currGain < gain[currNode]))
            continue;

        for (const auto &[nextNode, nextWeight] : adj[currNode]) {
            if (dist[nextNode] > currDist + nextWeight ||
                (dist[nextNode] == currDist + nextWeight &&
                 gain[nextNode] < currGain + wtank[nextNode])) {
                dist[nextNode] = currDist + nextWeight;
                gain[nextNode] = currGain + wtank[nextNode];
                pq.emplace(dist[nextNode], gain[nextNode], nextNode);
            }
        }
    }

    if (dist[t] == LLONG_MAX)
        cout << "-1\n";
    else
        cout << dist[t] << " " << gain[t] << "\n";

    return 0;
}