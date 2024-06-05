class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, INT_MAX);
        
        for(auto &word : words) {
            vector<int> subfreq(26, 0);

            for(char &ch : word) {
                subfreq[ch - 'a']++;
            }

            for(int i = 0; i < 26; i++) {
                freq[i] = min(freq[i], subfreq[i]);
            }
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < freq[i]; j++) {
                ans.push_back(string(1, 'a'+i));
            }
        }

        return ans;
    }
};
