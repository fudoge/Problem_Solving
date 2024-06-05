#pragma GCC optimize("03", "unroll-loops");

static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int n = s.size();
        unordered_map<char, char> mp;
        unordered_map<char, bool> mapped;


        for(int i = 0; i < n; i++) {
            if(!mp[s[i]]) {
                if(mapped[t[i]]) return false;
                mp[s[i]] = t[i];
                mapped[t[i]] = true;
            }

            s[i] = mp[s[i]];
        }

        return s == t;
    }
};