class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back({b, succProb[i]});
            graph[b].push_back({a, succProb[i]});
        }

        queue<pair<int, double>> q;
        q.push({start_node, 1.0});
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;

        while(!q.empty()) {
            int currNode = q.front().first;
            double currProb = q.front().second;
            q.pop();

            for(const auto &next : graph[currNode]) {
                int nextNode = next.first;
                double nextProb = next.second * currProb;

                if(nextProb > prob[nextNode]) {
                    prob[nextNode] = nextProb;
                    q.push({nextNode, nextProb});
                }
            }
        }

        return prob[end_node];
    }
};