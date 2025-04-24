#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
// 0 = LEFT, 1 = RIGHT, 2 = UP, 3 = DOWN

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, xs, ys, xe, ye;
    cin >> n >> xs >> ys >> xe >> ye;

    vector<pii> points;
    points.emplace_back(xs, ys);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    points.emplace_back(xe, ye);

    int m = n + 2;
    vector<vector<pii>> adj(m);
    unordered_map<int, vector<int>> sameX, sameY;
    for (int i = 0; i < m; i++) {
        sameY[points[i].second].emplace_back(i);
    }
    for (auto &[k, v] : sameY) {
        sort(v.begin(), v.end(),
             [&](int i, int j) { return points[i].first < points[j].first; });
        for (int i = 1; i < v.size(); i++) {
            int u = v[i - 1], w = v[i];
            adj[u].emplace_back(w, 1);
            adj[w].emplace_back(u, 0);
        }
    }

    for (int i = 0; i < m; i++) {
        sameX[points[i].first].emplace_back(i);
    }
    for (auto &[k, v] : sameX) {
        sort(v.begin(), v.end(),
             [&](int i, int j) { return points[i].second < points[j].second; });
        for (int i = 1; i < v.size(); i++) {
            int u = v[i - 1], w = v[i];
            adj[u].emplace_back(w, 2);
            adj[w].emplace_back(u, 3);
        }
    }

    deque<pii> dq;
    vector<array<int, 4>> dist(m);
    for (int i = 0; i < m; i++) {
        dist[i].fill(1e9);
    }
    for (int d = 0; d < 4; d++) {
        dist[0][d] = 0;
        dq.emplace_back(0, d);
    }

    while (!dq.empty()) {
        int curr, dir;
        tie(curr, dir) = dq.front();
        dq.pop_front();
        int curDist = dist[curr][dir];

        for (auto &elem : adj[curr]) {
            int next = elem.first;
            int nextDir = elem.second;

            int weight = (curr == 0 || dir == nextDir) ? 0 : 1;
            if (curDist + weight < dist[next][nextDir]) {
                dist[next][nextDir] = curDist + weight;
                if (weight == 0)
                    dq.emplace_front(next, nextDir);
                else
                    dq.emplace_back(next, nextDir);
            }
        }
    }

    int ans = *min_element(dist[m - 1].begin(), dist[m - 1].end());
    if (ans == 1e9) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}