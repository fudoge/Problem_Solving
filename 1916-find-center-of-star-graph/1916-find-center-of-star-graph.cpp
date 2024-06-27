class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for(const auto &edge : edges) {
            int a = edge[0];
            int b = edge[1];

            if(mp[a]) return a;
            if(mp[b]) return b;
            mp[a]++;
            mp[b]++;
        }
        return -1;
    }
};