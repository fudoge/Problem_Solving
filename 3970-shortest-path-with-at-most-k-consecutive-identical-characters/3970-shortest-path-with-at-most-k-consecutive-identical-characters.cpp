using ll = long long;
constexpr ll INF = LLONG_MAX / 4;

struct item {
    int node;
    int cnt;
    ll dist;

    item(int node, int cnt, ll dist)
        : node(node), cnt(cnt), dist(dist) {}
};

struct comp {
    bool operator()(const item &a, const item &b) {
        return a.dist > b.dist;
    }
};

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }       

        priority_queue<item, vector<item>, comp> pq;
        // dist[node][cnt]
        vector<vector<ll>> dist(n, vector<ll>(k+1, INF));
        dist[0][1] = 0;
        pq.push(item(0, 1, 0));

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int node = curr.node;
            int cnt = curr.cnt;

            if(curr.dist > dist[node][cnt]) continue;

            for(const auto &next : adj[curr.node]) {
                int nextNode = next.first;
                int weight = next.second;

                int nextCnt;
                if(labels[node] == labels[nextNode]) {
                    nextCnt = cnt + 1;
                } else {
                    nextCnt = 1;
                }

                if(nextCnt > k) continue;

                ll nextDist = curr.dist + weight;
                if(nextDist < dist[nextNode][nextCnt]) {
                    dist[nextNode][nextCnt] = nextDist;
                    pq.push(item(nextNode, nextCnt, nextDist));
                }
            }
        }

        ll ans = INF;
        for(int i = 1; i <= k; i++) {
            ans = min(ans, dist[n-1][i]);
        }

        return ans == INF ? -1 : (int)ans;
    }
};