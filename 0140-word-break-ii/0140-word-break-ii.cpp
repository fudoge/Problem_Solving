class Solution {
public:
    bool check(string &s, string &word, int idx) {
        int i = 0;
        while(i < word.size()) {
            if(i + idx >= s.size() || s[i + idx] != word[i]) return false;
            i++;
        }

        return true;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //dp[idx] idx번부터 인식한 뒤의 suffix들.
        //ex) s = "~~dog", word Dict = ["dog", ...] => dp[n-3] = {"dog"}.
        int n = s.size();
        vector<vector<string>> dp(n+1, vector<string>());
        dp[n] = {""};
        for(int i = n-1; i >= 0; i--) {
            for(string &word : wordDict) {
                if(check(s, word, i)) {
                    for(string suffix : dp[i + word.size()]) {
                        dp[i].push_back(word + " " + suffix);
                    }
                }
            }
        }

        for(string &sentence : dp[0]) {
            sentence.pop_back();
        }
        return dp[0];
    }
};