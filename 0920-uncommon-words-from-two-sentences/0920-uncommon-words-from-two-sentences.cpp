class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;

        stringstream ss1(s1);
        stringstream ss2(s2);

        string token;
        vector<string> ans;
        while(ss1 >> token) {
            mp1[token]++;
        }

        while(ss2 >> token) {
            mp2[token]++;
        }

        for(auto &element : mp1) {
            if(element.second == 1 &&  mp2[element.first] < 1) ans.push_back({element.first});
        }

        for(auto &element : mp2) {
            if(element.second == 1 &&  mp1[element.first] < 1) ans.push_back({element.first});
        }

        return ans;
    }
};