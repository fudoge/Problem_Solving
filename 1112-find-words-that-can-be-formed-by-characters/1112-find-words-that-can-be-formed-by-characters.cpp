class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<char, int> charTable;
        int answer = 0;

        for(const auto &ch : chars) 
            charTable[ch]++;
        
        for(const auto &word : words) {
            unordered_map<char, int> tempTable;
            bool flag = true;
            for(const auto &ch : word) {
                tempTable[ch]++;
                if(tempTable[ch] > charTable[ch]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                answer += word.size();
            }
        }

        return answer;
    }
};