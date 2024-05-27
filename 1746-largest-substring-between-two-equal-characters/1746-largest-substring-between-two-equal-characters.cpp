class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        const int n = s.size();
        unordered_map<char, int> um;
        int maxGap = -1;

        for(int i = 0; i < n; i++) {
            if(um[s[i]]) maxGap = max(maxGap, i - um[s[i]]);
            else um[s[i]] = i+1;
        }

        return maxGap;
    }
};