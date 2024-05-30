class Solution {
public:
    bool isP(string& word) {
        for(int i = 0; i < word.size()/2; i++) {
            if(word[i] != word[word.size()-i-1]) return false;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(string &word: words) {
            if(isP(word)) return word;
        }

        return "";
    }
};