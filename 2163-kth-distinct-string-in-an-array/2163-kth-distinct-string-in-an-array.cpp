#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        for(const auto &str : arr) {
            mp[str]++;
        }

        for(const auto &str : arr) {
            if(mp[str] == 1) {
                if(--k == 0) return str;
            }
        }

        return "";
    }
};