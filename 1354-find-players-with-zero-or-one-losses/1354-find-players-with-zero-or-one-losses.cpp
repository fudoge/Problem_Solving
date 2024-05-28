static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer(2, vector<int>());
        unordered_map<int, int> mp;

        for(const auto &match : matches) {
            if(!mp[match[0]]) mp[match[0]] = 0;
            mp[match[1]]++;
        }

        for(const auto &m : mp) {
            if(m.second == 1) {
                answer[1].emplace_back(m.first);
            } else if(m.second == 0) {
                answer[0].emplace_back(m.first);
            }
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());

        return answer;
    }
};
