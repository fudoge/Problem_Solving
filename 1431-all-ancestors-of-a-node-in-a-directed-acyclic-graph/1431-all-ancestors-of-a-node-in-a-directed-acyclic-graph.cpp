class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> answer(n);
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        
        for (const auto &edge : edges) {
            int src = edge[0];
            int dst = edge[1];
            graph[src].push_back(dst);
            indegree[dst]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (const auto &nextNode : graph[curr]) {
                for (int ancestor : answer[curr]) {
                    if(find(answer[nextNode].begin(), answer[nextNode].end(), ancestor) == answer[nextNode].end())
                        answer[nextNode].push_back(ancestor);
                }
                if(find(answer[nextNode].begin(), answer[nextNode].end(), curr) == answer[nextNode].end())
                    answer[nextNode].push_back(curr);
                if (--indegree[nextNode] == 0) {
                    q.push(nextNode);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            sort(answer[i].begin(), answer[i].end());
        }

        return answer;
    }
};