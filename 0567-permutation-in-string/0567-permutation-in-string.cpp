#pragma GCC optimize("03", "unroll-loops")
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> count(26, 0);
        for (char c : s1) {
            count[c - 'a']++;
        }

        int left = 0, right = 0, to_match = s1.size();
        
        while (right < s2.size()) {
            if (count[s2[right] - 'a'] > 0) {
                to_match--;
            }
            count[s2[right] - 'a']--;
            right++;

            if (to_match == 0) return true;

            if (right - left == s1.size()) {
                if (++count[s2[left] - 'a'] > 0) {
                    to_match++;
                }
                left++;
            }
        }

        return false;
    }
};