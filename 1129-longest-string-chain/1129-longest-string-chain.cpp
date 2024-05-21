class Solution {
public:
    bool isPredecessor(string A, string B)
    {
        int n = A.size();
        int m = B.size();

        if(m-n != 1) return false;

        int a = 0;
        int b = 0;

        while (a < n && b < m) {
        if (A[a] != B[b]) {
            b++;
        } else {
            a++;
            b++;
        }
    }

        return a == n;
    }

    int longestStrChain(vector<string>& words) {
        const int n = words.size();
        vector<vector<string>> dp(n);

        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            if(a.size() == b.size()) {
                return a < b;
            }
            return a.size() < b.size();
        });

        dp[0].push_back(words[0]);

        int longestLength = -1;
        for(int i = 1; i < n; i++) {
            int idxToAppend = -1;
            int longestIdx = 0;
            for(int j = i-1; j >= 0; j--) {
                if(dp[j].size() >= longestIdx && isPredecessor(words[j], words[i])) {
                    idxToAppend = j;
                    longestIdx = dp[j].size();
                }
            }
            if(idxToAppend != -1){
                dp[i].assign(dp[idxToAppend].begin(), dp[idxToAppend].end());
            }
            dp[i].push_back(words[i]);

            longestLength = max(longestLength, static_cast<int>(dp[i].size()));
        }

        if(longestLength <= 0) {
            longestLength = 1;
        }
        return longestLength;
    }
};