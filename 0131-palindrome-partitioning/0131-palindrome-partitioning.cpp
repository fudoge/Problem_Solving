class Solution {
private:
    vector<vector<string>> ans;
    vector<vector<bool>> isPalindrome;
    int n;
public:
    void solve(string &s, vector<string> &substring_seq, int idx) {
        if(idx >= n) {
            ans.push_back(substring_seq);
            return;
        }
        for(int i = idx; i < n; i++) {
            string subs = s.substr(idx, i - idx + 1);
            if(isPalindrome[idx][i]) {
                substring_seq.push_back(subs);
                solve(s, substring_seq, i+1);
                substring_seq.pop_back();
            }
        }
    };

    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> substring_seq = {};

        isPalindrome.resize(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
            }
        }
        for(int length = 3; length <= n; length++) {
            for(int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                if(s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                    isPalindrome[i][j] = true;
                }
            }
        }

        solve(s, substring_seq, 0);
        return ans;
    }
};