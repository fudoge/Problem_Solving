class Solution {
public:
    int countPalindromicSubsequence(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int count = 0;
        vector<int> firstIdx(26, INT_MAX);
        vector<int> lastIdx(26);

        for(int i = 0; i < s.size(); i++) {
            firstIdx[s[i] - 'a'] = min(firstIdx[s[i] - 'a'], i);
            lastIdx[s[i] - 'a'] = i;
        }

        for(int i = 0; i < 26; i++) {
            if(firstIdx[i] < lastIdx[i]) {
                count += set<char>(begin(s) + firstIdx[i] + 1, begin(s) + lastIdx[i]).size();
            }
        }

        return count;
    }
};