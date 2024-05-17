class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> not_roots;

        for (const auto& edge : edges) {
            not_roots.insert(edge[1]);
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (not_roots.count(i) == 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};