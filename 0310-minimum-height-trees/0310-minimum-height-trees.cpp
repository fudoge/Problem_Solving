#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> graph(n);
        vector<bool> visited(n, 0);
        vector<int> indegree(n, 0);
        vector<int> ans;

        for(const auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 1) {
                q.push(i);
                visited[i] = true;
            }
        }

        while(!q.empty()) {
            int qsize = q.size();
            ans = {};

            for(int i = 0; i < qsize; i++) {
                auto curr = q.front();
                q.pop();
                ans.push_back(curr);

                for(const auto &next : graph[curr]) {
                    if(!visited[next]) {
                        indegree[next]--;
                        if(indegree[next] <= 1) {
                            q.push(next);
                            visited[next] = true;
                        }
                    }
                }
            }
        }

        return ans;
    }
};