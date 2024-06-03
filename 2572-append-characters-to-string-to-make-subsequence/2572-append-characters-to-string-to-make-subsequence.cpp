class Solution {
public:
    int appendCharacters(string s, string t) {
        if(s == t) return 0;
        
        int i = 0, j = 0;
        while(i < s.size()) {
            while(i < s.size() && j < t.size() && s[i] == t[j]) {
                i++;
                j++;
            }
            i++;
        }
        
        return t.size() - j;
    }
};