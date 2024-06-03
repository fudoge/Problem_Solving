class Solution {
public:
    int appendCharacters(string s, string t) {
        if(s == t) return 0;
        int n = s.size();
        int m = t.size();
        
        int i = 0, j = 0;
        while(i < n) {
            while(i < n && j < m && s[i] == t[j]) {
                i++;
                j++;
            }
            i++;
        }
        
        return m - j;
    }
};