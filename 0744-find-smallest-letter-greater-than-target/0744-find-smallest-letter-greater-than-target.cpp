class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = '|';
        for(const auto &let : letters) {
            if(let > target) {
                ans = min(ans, let);
            }
        }

        return ans == '|'? letters[0] : ans;
    }
};