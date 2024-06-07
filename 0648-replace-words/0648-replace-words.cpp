#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

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