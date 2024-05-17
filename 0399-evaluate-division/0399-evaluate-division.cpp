class Solution {
public:
    
    double dfs(const string& from, const string& to, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
        if (!graph.count(from) || !graph.count(to))
            return -1.0;
        if (from == to)
            return 1.0;
        visited.insert(from);
        for (const auto& neighbor : graph[from]) {
            if (!visited.count(neighbor.first)) {
                double result = dfs(neighbor.first, to, graph, visited);
                if (result != -1.0)
                    return neighbor.second * result;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); i++) {
            const string& dividend = equations[i][0];
            const string& divisor = equations[i][1];
            double value = values[i];

            graph[dividend][divisor] = value;
            graph[divisor][dividend] = 1.0 / value;
        }

        vector<double> results;
        for (const auto& query : queries) {
            const string& dividend = query[0];
            const string& divisor = query[1];
            unordered_set<string> visited;
            double result = dfs(dividend, divisor, graph, visited);
            results.push_back(result);
        }

        return results;
    }
};