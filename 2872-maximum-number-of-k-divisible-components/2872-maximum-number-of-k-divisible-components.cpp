#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
   public:
    int ans = 0;
    int k;
    vector<vector<int>> adj;
    ll dfs(int node, int parent, vector<int>& values) {
        ll currentSum = values[node];
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                currentSum += dfs(neighbor, node, values);
            }
        }

        if (currentSum % k == 0) {
            ans++;
            return 0;
        }
        return currentSum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        adj.resize(n);
        this->k = k;

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        dfs(0, -1, values);

        return ans;
    }
};