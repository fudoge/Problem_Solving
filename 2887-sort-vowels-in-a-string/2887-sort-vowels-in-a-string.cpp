class Solution {
public:
    string sortVowels(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<char> str;
        vector<int> vowelIdx;
        vector<char> vowels;
        unordered_map<char, int> isVowel = {
            {'a', 1},
            {'e', 1},
            {'i', 1},
            {'o', 1},
            {'u', 1},
            {'A', 1},
            {'E', 1},
            {'I', 1},
            {'O', 1},
            {'U', 1}
        };

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(isVowel[ch] == 1) {
                vowels.push_back(ch);
                vowelIdx.push_back(i);
            } 
            str.push_back(ch);
        }

        sort(vowels.begin(), vowels.end());

        for(int i = 0; i < vowels.size(); i++) {
            str[vowelIdx[i]] = vowels[i];
        }

        string sorted = "";
        for(const auto &ch : str) {
            sorted += ch;
        }

        return sorted;
    }
};