class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++; // stops -> steps
        unordered_map<int, vector<pair<int, int>>> graph;
        for(const auto &flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});

        while(!q.empty() && k > 0) {
            int qSize = q.size();
            for(int i = 0; i < qSize; i++) {
                auto curr = q.front();
                q.pop(); 

                for(const auto &next : graph[curr.first]) {
                    if(dist[next.first] <= curr.second + next.second) continue;
                    dist[next.first] = curr.second + next.second;
                    q.push({next.first, dist[next.first]});
                }
            }
            k--;
        }

        return dist[dst] == 1e9? -1 : dist[dst];
    }
};