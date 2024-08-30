class Solution {
private:
    void dijkstra(const vector<vector<pair<int, int>>> &graph, vector<vector<int>> &edges, vector<vector<int>> &dist, int source, int difference, int run) {
        int n = graph.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, source});
        dist[source][run] = 0;

        while(!pq.empty()) {
            auto [currDist, currNode] = pq.top();
            pq.pop();
            if (currDist > dist[currNode][run]) continue;

            for (auto &next : graph[currNode]) {
                int nextNode = next.first;
                int edgeIdx = next.second;
                int weight = edges[edgeIdx][2];

                if (weight == -1) weight = 1;

                if (run == 1 && edges[edgeIdx][2] == -1) {
                    int newWeight = difference + dist[nextNode][0] - dist[currNode][1];
                    if(newWeight > weight) {
                        edges[edgeIdx][2] = weight = newWeight;
                    }
                }

                if (dist[nextNode][run] > dist[currNode][run] + weight) {
                    dist[nextNode][run] = dist[currNode][run] + weight;
                    pq.push({dist[nextNode][run], nextNode});
                }
            }
        }
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> graph(n);

        for(int i = 0; i < edges.size(); i++) {
            int src = edges[i][0];
            int dst = edges[i][1];
            graph[src].push_back({dst, i});
            graph[dst].push_back({src, i});
        }

        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        dist[source][0] = dist[source][1] = 0;

        dijkstra(graph, edges, dist, source, 0, 0);
        int diff = target - dist[destination][0];
        if(diff < 0) return {};
        dijkstra(graph, edges, dist, source, diff, 1);
        if(dist[destination][1] < target) return {};

        for (auto &edge : edges) {
            if(edge[2] == -1) edge[2] = 1;
        }
        return edges;
    }
};