#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using pii = pair<int, int>;
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> adj(n);
        for(const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }       

        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.emplace(0, 0);
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int currDist = curr.first;
            int currNode = curr.second;
            if(currDist > dist[currNode]) continue;
            for(auto next : adj[currNode]) {
                int nextDist = currDist + next.second;
                int nextNode = next.first;
                if(nextDist < dist[nextNode]) {
                    dist[nextNode] = nextDist;
                    pq.emplace(nextDist, nextNode);
                }
            }
        }

        return dist[n-1] == INT_MAX? -1 : dist[n-1];
    }
};