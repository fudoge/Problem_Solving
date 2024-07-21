class Solution {
public:
    vector<int> topologicalSort(int k, vector<vector<int>>& graph, vector<int>& indegree) {
        vector<int> order;
        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (const int &neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if (order.size() == k) return order;
        else return {};
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowGraph(k + 1);
        vector<int> rowIndegree(k + 1, 0);
        for (const auto &cond : rowConditions) {
            rowGraph[cond[0]].push_back(cond[1]);
            rowIndegree[cond[1]]++;
        }

        vector<vector<int>> colGraph(k + 1);
        vector<int> colIndegree(k + 1, 0);
        for (const auto &cond : colConditions) {
            colGraph[cond[0]].push_back(cond[1]);
            colIndegree[cond[1]]++;
        }

        vector<int> rowOrder = topologicalSort(k, rowGraph, rowIndegree);
        vector<int> colOrder = topologicalSort(k, colGraph, colIndegree);

        if (rowOrder.empty() || colOrder.empty()) return {};

        vector<int> rowPosition(k + 1, 0);
        vector<int> colPosition(k + 1, 0);
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 1; i <= k; ++i) {
            matrix[rowPosition[i]][colPosition[i]] = i;
        }

        return matrix;
    }
};