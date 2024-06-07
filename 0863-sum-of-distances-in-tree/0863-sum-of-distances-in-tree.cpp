class Solution {
private:
    vector<vector<int>> graph;
    vector<int> subtreeSize;
    vector<int> ans;
    int n;

    void dfs(int node, int parent) {
        subtreeSize[node] = 1;
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node);
                subtreeSize[node] += subtreeSize[child];
                ans[node] += ans[child] + subtreeSize[child];
            }
        }
    }

    void dfs2(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                ans[child] = ans[node] - subtreeSize[child] + n - subtreeSize[child];
                dfs2(child, node);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph.resize(n);
        subtreeSize.resize(n, 0);
        ans.resize(n, 0);

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);
        dfs2(0, -1);

        return ans;
    }
};
