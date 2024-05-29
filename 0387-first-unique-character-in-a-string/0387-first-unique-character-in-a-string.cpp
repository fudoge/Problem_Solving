class Solution {
public:
    int firstUniqChar(string s) {
        const int n = s.size();
        unordered_map<int, int> mp;

        for(const auto &ch : s) {
            mp[ch]++;
        }

        for(int i = 0; i < n; i++) {
            if(mp[s[i]] == 1) return i;
        }
        return -1;
    }
};