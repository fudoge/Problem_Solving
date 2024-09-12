class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> table(26, false);

        for(char &ch : allowed) {
            table[ch - 'a'] = true;
        }

        int ans = 0;
        for(auto &word : words) {
            bool flag = true;
            for(auto &ch : word) {
                if(!table[ch - 'a']) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};