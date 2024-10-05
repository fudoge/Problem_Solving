#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool check(unordered_map<char, int>& mp) {
        for(const auto &[k, v] : mp) {
            if(v != 0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;

        for(const auto &ch : s1) {
            mp[ch]++;
        }
        
        for(int i = 0; i < n; ++i) {
            mp[s2[i]]--;
            if(mp[s2[i]] == 0 && check(mp)) return true;
        }

        for(int i = n; i < m; ++i) {
            mp[s2[i-n]]++;
            mp[s2[i]]--;
            if(mp[s2[i]] == 0 && check(mp)) return true;
        }

        return false;
    }
};