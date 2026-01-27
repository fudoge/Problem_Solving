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

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int currNode = curr.first;
            int currDist = curr.second;
            if(currDist > dist[currNode]) continue;
            for(auto next : adj[currNode]) {
                int nextDist = currDist + next[1];
                int nextNode = next[0];
                if(nextDist < dist[nextNode]) {
                    dist[nextNode] = nextDist;
                    q.emplace(nextNode, nextDist);
                }
            }
        }

        return dist[n-1] == INT_MAX? -1 : dist[n-1];
    }
};