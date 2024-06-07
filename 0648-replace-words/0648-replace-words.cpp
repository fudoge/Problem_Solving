class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string ans = "";
        string word;
        while(ss >> word) {
            bool flag = true;
            for(int i = 0; i < word.size(); i++) {
                string prefix = word.substr(0, i);
                if(find(dictionary.begin(), dictionary.end(), prefix) != dictionary.end()) {
                    ans += prefix;
                    flag = false;
                    break;
                }
            }

            if(flag) {
                ans += word;
            }
            ans += " ";
        }

        ans.pop_back();
        return ans;
    }
};