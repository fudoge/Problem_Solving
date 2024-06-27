class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> indegree(n+1, 0);

        for(const auto &edge : edges) {
            int a = edge[0];
            int b = edge[1];

            indegree[a]++;
            indegree[b]++;
        }

        return max_element(indegree.begin(), indegree.end()) - indegree.begin();
    }
};