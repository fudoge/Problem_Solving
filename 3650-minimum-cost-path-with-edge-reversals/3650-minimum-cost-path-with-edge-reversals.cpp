#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n);
        for(const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }       

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
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
                int nextDist = currDist + next[1];
                int nextNode = next[0];
                if(nextDist < dist[nextNode]) {
                    dist[nextNode] = nextDist;
                    pq.emplace(nextDist, nextNode);
                }
            }
        }

        return dist[n-1] == INT_MAX? -1 : dist[n-1];
    }
};