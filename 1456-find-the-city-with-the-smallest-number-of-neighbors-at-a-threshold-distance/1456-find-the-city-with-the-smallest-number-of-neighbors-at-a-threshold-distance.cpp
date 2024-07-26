class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n); // graph[from] = [[to, cost], [to, cost]]
        vector<int> boundaries(n, 0); // boundaries[i] = <number of neighbors>
        for(const auto &edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int cost = edge[2];

            graph[from].push_back({to, cost});
            graph[to].push_back({from, cost});
        }

        for(int i = 0; i < n; i++) {
            vector<int> minDistance(n, INT_MAX);
            queue<int> q;
            q.push(i);
            minDistance[i] = 0;

            while(!q.empty()) {
                int currNode = q.front();
                q.pop();

                for(const auto &nextInfo : graph[currNode]) {
                    int nextNode = nextInfo.first;
                    int nextCost = nextInfo.second;

                    if(minDistance[currNode] + nextCost < minDistance[nextNode]) {
                        minDistance[nextNode] = minDistance[currNode] + nextCost;
                        
                        q.push(nextNode);
                    }
                }
            }

            int neighbor = 0;
            for(int j = 0; j < n; j++) {
                if(minDistance[j] <= distanceThreshold) neighbor++;
            }
            boundaries[i] = neighbor-1;
        }

        int ans = -1;
        int minNeighbor = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(boundaries[i] < minNeighbor) {
                ans = i;
                minNeighbor = boundaries[i];
            } else if(boundaries[i] == minNeighbor) {
                ans = i;
            }
            cout << boundaries[i] << endl;
        }

        return ans;
    }
};