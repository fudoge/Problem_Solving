class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string temp = s + "#" + rev_s;
        vector<int> lps(temp.size(), 0);
        
        for (int i = 1; i < temp.size(); ++i) {
            int len = lps[i - 1];
            while (len > 0 && temp[i] != temp[len]) {
                len = lps[len - 1];
            }
            if (temp[i] == temp[len]) {
                ++len;
            }
            lps[i] = len;
        }
        
        string add_on = rev_s.substr(0, s.size() - lps.back());
        return add_on + s;
    }
};