static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();


class Solution {
public:
    bool makeEqual(vector<string>& words) {
        const int n = words.size();
        unordered_map<char, int> um;

        for(const auto &word:words) {
            for(const auto &ch:word) {
                um[ch]++;
            }
        }

        for(const auto &table : um) {
            if(table.second%n) return false;
        }

        return true;
    }
};