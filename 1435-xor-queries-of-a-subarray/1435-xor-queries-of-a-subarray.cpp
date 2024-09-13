class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(const auto &query : queries) {
            int from = query[0];
            int to = query[1];

            int res = arr[from];
            for(int i = from+1; i <= to; ++i) {
                res ^= arr[i];
            }
            ans.push_back(res);
        }

        return ans;
    }
};