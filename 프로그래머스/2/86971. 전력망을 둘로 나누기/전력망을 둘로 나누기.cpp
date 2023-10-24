#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int start, vector<int>& visited, vector<vector<int>>& graph) {
    int nodes = 1;
    visited[start] = true;
    
    for (auto node : graph[start]) {
        if (!visited[node]) {
            nodes += dfs(node, visited, graph);
        }
    }
    
    return nodes;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> graph(n + 1);
        
        for (int j = 0; j < wires.size(); j++) {
            if (i != j) {
                int a = wires[j][0];
                int b = wires[j][1];
                
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
        }
        
        vector<int> visited(n + 1, false);
        
        int a = wires[i][0];
        int b = wires[i][1];
        
        int nodesA = dfs(a, visited, graph);
        int nodesB = n - nodesA;
        
        int diff = abs(nodesA - nodesB);
        answer = min(answer, diff);
    }
    
    return answer;
}