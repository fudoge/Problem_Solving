#pragma GCC optimize("03". "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = cost.size();
        int m = source.size();
        vector<vector<pair<int, int>>> graph(26);
        vector<vector<int>> costs(26, vector<int>(26, INT_MAX));
        for(int i = 0; i < n; i++) {
            int src = original[i] - 'a';
            int dst = changed[i] - 'a';
            int costToChange = cost[i];

            graph[src].push_back({dst, costToChange});
        }

        for(int i = 0; i < 26; i++) {
            queue<int> q;
            q.push(i);
            costs[i][i] = 0;

            while(!q.empty()) {
                int curr = q.front();
                q.pop();

                for(const auto &next : graph[curr]) {
                    int nextLetter = next.first;
                    int nextCost = next.second;

                    if(costs[i][curr] + nextCost < costs[i][nextLetter]) {
                        q.push(nextLetter);
                        costs[i][nextLetter] = costs[i][curr] + nextCost;
                    }
                }
            }
        }

        long long ans = 0;
        for(int i = 0; i < m; i++) {
            int src = source[i] - 'a';
            int dst = target[i] - 'a';
            if(costs[src][dst] == INT_MAX) return -1;
            ans += costs[src][dst];
        }

        return ans;
    }
};