class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";
        int i = 0;

        while(i < sentence.size()) {
            string prefix = "";
            while(i < sentence.size() && sentence[i] != ' ') {
                prefix += sentence[i];
                if(find(dictionary.begin(), dictionary.end(), prefix) != dictionary.end()) {
                    while(i < sentence.size() && sentence[i] != ' ') i++;
                    break;
                }
                i++;
            }

            ans += prefix;
            ans += " ";
            i++;
        }

        ans.pop_back();
        return ans;
    }
};