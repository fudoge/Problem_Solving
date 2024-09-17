class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;

        stringstream ss1(s1);
        stringstream ss2(s2);

        string token;
        vector<string> ans;
        while(ss1 >> token) {
            mp[token]++;
        }

        while(ss2 >> token) {
            mp[token]++;
        }

        for(auto &element : mp) {
            if(element.second == 1) ans.push_back(element.first);
        }

        return ans;
    }
};