class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> priority(26, 1e9);
        for(int i = 0; i < order.size(); i++) {
            priority[order[i] - 'a'] = i;
        }

        sort(s.begin(), s.end(), [priority](const auto &a, const auto &b){
            return priority[a - 'a'] < priority[b - 'a'];
        });

        return s;
    }
};