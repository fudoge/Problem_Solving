class Solution {
public:
    bool checkString(string s) {
        int bc = 0;
        for(char ch : s) {
            if(ch == 'b') {
                bc++;
            } else {
                if(bc > 0) return false;
            }
        }

        return true;
    }
};