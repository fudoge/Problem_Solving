class Solution {
private:
    int n;
public:
    bool check(string &s, string &word, int idx, int wordlen) {
        int i = 0;
        while(i < wordlen) {
            if(i + idx >= n || s[i + idx] != word[i]) return false;
            i++;
        }

        return true;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // dp[idx] = idx번부터 인식한 뒤의 suffix들.
        // ex) s = "~~dog", word Dict = ["dog", ...] => dp[n-3] = {"dog ", ...}.
        // 마지막 공백은 지워주면 된다.
        
        n = s.size();
        vector<vector<string>> dp(n+1, vector<string>());
        dp[n] = {""};
        for(int i = n-1; i >= 0; i--) {
            for(string &word : wordDict) {
                int wordlen = word.size();
                if(check(s, word, i, wordlen)) {
                    for(string suffix : dp[i + wordlen]) {
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