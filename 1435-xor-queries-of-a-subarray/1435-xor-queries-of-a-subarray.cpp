#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> table(arr.size());
        vector<int> ans;
        table[0] = arr[0];
        for(int i = 1; i < arr.size(); ++i) {
            table[i] = table[i-1] ^ arr[i];
        }

        for(const auto &query : queries) {
            int from = query[0];
            int to = query[1];
            
            if(from == 0) ans.push_back(table[to]);
            else ans.push_back(table[from-1] ^ table[to]);
        }
        return ans;
    }
};